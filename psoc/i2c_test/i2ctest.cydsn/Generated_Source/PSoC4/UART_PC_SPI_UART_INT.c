/*******************************************************************************
* File Name: UART_PC_SPI_UART_INT.c
* Version 1.20
*
* Description:
*  This file provides the source code to the Interrupt Service Routine for
*  the SCB Component in SPI and UART modes.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "UART_PC_PVT.h"
#include "UART_PC_SPI_UART_PVT.h"


/*******************************************************************************
* Function Name: UART_PC_SPI_UART_ISR
********************************************************************************
*
* Summary:
*  Handles the Interrupt Service Routine for the SCB SPI or UART modes.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
CY_ISR(UART_PC_SPI_UART_ISR)
{
#if(UART_PC_INTERNAL_RX_SW_BUFFER_CONST)
    uint32 locHead;
    uint32 dataRx;
#endif /* (UART_PC_INTERNAL_RX_SW_BUFFER_CONST) */

#if(UART_PC_INTERNAL_TX_SW_BUFFER_CONST)
    uint32 locTail;
#endif /* (UART_PC_INTERNAL_TX_SW_BUFFER_CONST) */

    if(NULL != UART_PC_customIntrHandler)
    {
        UART_PC_customIntrHandler();
    }

    #if(UART_PC_CHECK_SPI_WAKE_ENABLE)
    {
        /* Clear SPI wakeup source */
        UART_PC_ClearSpiExtClkInterruptSource(UART_PC_INTR_SPI_EC_WAKE_UP);
    }
    #endif

    #if(UART_PC_CHECK_RX_SW_BUFFER)
    {
        if(UART_PC_CHECK_INTR_RX_MASKED(UART_PC_INTR_RX_NOT_EMPTY))
        {
            while(0u != UART_PC_GET_RX_FIFO_ENTRIES)
            {
                /* Get data from RX FIFO */
                dataRx = UART_PC_RX_FIFO_RD_REG;

                /* Move local head index */
                locHead = (UART_PC_rxBufferHead + 1u);

                /* Adjust local head index */
                if(UART_PC_RX_BUFFER_SIZE == locHead)
                {
                    locHead = 0u;
                }

                if(locHead == UART_PC_rxBufferTail)
                {
                    /* Overflow: through away new data */
                    UART_PC_rxBufferOverflow = (uint8) UART_PC_INTR_RX_OVERFLOW;
                }
                else
                {
                    /* Store received data */
                    UART_PC_PutWordInRxBuffer(locHead, dataRx);

                    /* Move head index */
                    UART_PC_rxBufferHead = locHead;
                }
            }

            UART_PC_ClearRxInterruptSource(UART_PC_INTR_RX_NOT_EMPTY);
        }
    }
    #endif


    #if(UART_PC_CHECK_TX_SW_BUFFER)
    {
        if(UART_PC_CHECK_INTR_TX_MASKED(UART_PC_INTR_TX_NOT_FULL))
        {
            /* Put data into TX FIFO */
            while(UART_PC_FIFO_SIZE != UART_PC_GET_TX_FIFO_ENTRIES)
            {
                /* Check for a room in TX software buffer */
                if(UART_PC_txBufferHead != UART_PC_txBufferTail)
                {
                    /* Move local tail index */
                    locTail = (UART_PC_txBufferTail + 1u);

                    /* Adjust local tail index */
                    if(UART_PC_TX_BUFFER_SIZE == locTail)
                    {
                        locTail = 0u;
                    }

                    /* Put data into TX FIFO */
                    UART_PC_TX_FIFO_WR_REG = UART_PC_GetWordFromTxBuffer(locTail);

                    /* Move tail index */
                    UART_PC_txBufferTail = locTail;
                }
                else
                {
                    /* TX software buffer is empty: complete transmition */
                    UART_PC_DISABLE_INTR_TX(UART_PC_INTR_TX_NOT_FULL);
                    break;
                }
            }

            UART_PC_ClearTxInterruptSource(UART_PC_INTR_TX_NOT_FULL);
        }
    }
    #endif
}


/* [] END OF FILE */
