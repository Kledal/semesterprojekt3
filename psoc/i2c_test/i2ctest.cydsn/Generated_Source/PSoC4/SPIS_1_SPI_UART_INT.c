/*******************************************************************************
* File Name: SPIS_1_SPI_UART_INT.c
* Version 1.10
*
* Description:
*  This file provides the source code to the Interrupt Servive Routine for
*  the SCB Component in SPI and UART modes.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPIS_1_PVT.h"
#include "SPIS_1_SPI_UART_PVT.h"


/*******************************************************************************
* Function Name: SPIS_1_SPI_UART_ISR
********************************************************************************
*
* Summary:
*  Handles Interrupt Service Routine for SCB SPI or UART modes.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
CY_ISR(SPIS_1_SPI_UART_ISR)
{
    #if(SPIS_1_INTERNAL_RX_SW_BUFFER_CONST)
        uint32 locHead;
        uint32 dataRx;
    #endif /* (SPIS_1_INTERNAL_RX_SW_BUFFER_CONST) */

    #if(SPIS_1_INTERNAL_TX_SW_BUFFER_CONST)
        uint32 locTail;
    #endif /* (SPIS_1_INTERNAL_TX_SW_BUFFER_CONST) */

    if(NULL != SPIS_1_customIntrHandler)
    {
        SPIS_1_customIntrHandler(); /* Call customer routine if needed */
    }

    #if(SPIS_1_CHECK_SPI_WAKE_ENABLE)
    {
        /* Clear SPI wakeup source */
        SPIS_1_ClearSpiExtClkInterruptSource(SPIS_1_INTR_SPI_EC_WAKE_UP);
    }
    #endif

    #if(SPIS_1_CHECK_RX_SW_BUFFER)
    {
        /* Get data from RX FIFO */
        if(SPIS_1_CHECK_INTR_RX_MASKED(SPIS_1_INTR_RX_NOT_EMPTY))
        {
            while(0u != SPIS_1_GET_RX_FIFO_ENTRIES)
            {
                /* Get data from RX FIFO */
                dataRx = SPIS_1_RX_FIFO_RD_REG;

                /* Move local head index */
                locHead = (SPIS_1_rxBufferHead + 1u);

                /* Adjust local head index */
                if(SPIS_1_RX_BUFFER_SIZE == locHead)
                {
                    locHead = 0u;
                }

                if(locHead == SPIS_1_rxBufferTail)
                {
                    /* Overflow: through away new data */
                    SPIS_1_rxBufferOverflow = (uint8) SPIS_1_INTR_RX_OVERFLOW;
                }
                else
                {
                    /* Store received data */
                    SPIS_1_PutWordInRxBuffer(locHead, dataRx);

                    /* Move head index */
                    SPIS_1_rxBufferHead = locHead;
                }
            }

            SPIS_1_ClearRxInterruptSource(SPIS_1_INTR_RX_NOT_EMPTY);
        }
    }
    #endif


    #if(SPIS_1_CHECK_TX_SW_BUFFER)
    {
        if(SPIS_1_CHECK_INTR_TX_MASKED(SPIS_1_INTR_TX_NOT_FULL))
        {
            /* Put data into TX FIFO */
            while(SPIS_1_FIFO_SIZE != SPIS_1_GET_TX_FIFO_ENTRIES)
            {
                /* There is a data in TX software buffer */
                if(SPIS_1_txBufferHead != SPIS_1_txBufferTail)
                {
                    /* Mode local tail index */
                    locTail = (SPIS_1_txBufferTail + 1u);

                    /* Adjust local tail index */
                    if(SPIS_1_TX_BUFFER_SIZE == locTail)
                    {
                        locTail = 0u;
                    }

                    /* Put data into TX FIFO */
                    SPIS_1_TX_FIFO_WR_REG = SPIS_1_GetWordFromTxBuffer(locTail);

                    /* Mode tail index */
                    SPIS_1_txBufferTail = locTail;
                }
                else
                {
                    /* TX software buffer is EMPTY: end of transmitting */
                    SPIS_1_DISABLE_INTR_TX(SPIS_1_INTR_TX_NOT_FULL);
                    break;
                }
            }

            SPIS_1_ClearTxInterruptSource(SPIS_1_INTR_TX_NOT_FULL);
        }
    }
    #endif
}


/* [] END OF FILE */
