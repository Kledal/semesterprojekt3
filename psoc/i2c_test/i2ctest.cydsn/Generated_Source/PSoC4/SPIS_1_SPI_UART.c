/*******************************************************************************
* File Name: SPIS_1_SPI_UART.c
* Version 1.10
*
* Description:
*  This file provides the source code to the API for the SCB Component in
*  SPI and UART modes.
*
* Note:
*
*******************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPIS_1_PVT.h"
#include "SPIS_1_SPI_UART_PVT.h"

/***************************************
*        SPI/UART Private Vars
***************************************/

#if(SPIS_1_INTERNAL_RX_SW_BUFFER_CONST)
    volatile uint32 SPIS_1_rxBufferHead;
    volatile uint32 SPIS_1_rxBufferTail;
    volatile uint8  SPIS_1_rxBufferOverflow;
#endif /* (SPIS_1_INTERNAL_RX_SW_BUFFER_CONST) */

#if(SPIS_1_INTERNAL_TX_SW_BUFFER_CONST)
    volatile uint32 SPIS_1_txBufferHead;
    volatile uint32 SPIS_1_txBufferTail;
#endif /* (SPIS_1_INTERNAL_TX_SW_BUFFER_CONST) */

#if(SPIS_1_INTERNAL_RX_SW_BUFFER)
    /* Add one element to the buffer to receive full packet. One byte in receive buffer is always empty */
    volatile uint16 SPIS_1_rxBufferInternal[SPIS_1_RX_BUFFER_SIZE];
#endif /* (SPIS_1_INTERNAL_RX_SW_BUFFER) */

#if(SPIS_1_INTERNAL_TX_SW_BUFFER)
    volatile uint16 SPIS_1_txBufferInternal[SPIS_1_TX_BUFFER_SIZE];
#endif /* (SPIS_1_INTERNAL_TX_SW_BUFFER) */


#if(SPIS_1_RX_DIRECTION)

    /*******************************************************************************
    * Function Name: SPIS_1_SpiUartReadRxData
    ********************************************************************************
    *
    * Summary:
    *  Retrieves the next data element from the receive buffer. Undefined data will
    *  be returned if the RX buffer is empty.
    *  Call SPIS_1_SpiUartGetRxBufferSize() to return buffer size.
    *   - RX software buffer disabled: Returns data element retrieved from RX FIFO.
    *   - RX software buffer enabled: Returns data element from the software
    *     receive buffer.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Next data element from the receive buffer.
    *
    * Global Variables:
    *  Look into SPIS_1_SpiInit for description.
    *
    *******************************************************************************/
    uint32 SPIS_1_SpiUartReadRxData(void)
    {
        uint32 rxData = 0u;

        #if(SPIS_1_INTERNAL_RX_SW_BUFFER_CONST)
            uint32 locTail;
        #endif /* (SPIS_1_INTERNAL_RX_SW_BUFFER_CONST) */

        #if(SPIS_1_CHECK_RX_SW_BUFFER)
        {
            if(SPIS_1_rxBufferHead != SPIS_1_rxBufferTail)
            {
                /* There is data in RX software buffer */

                /* Calculate index to read from */
                locTail = (SPIS_1_rxBufferTail + 1u);

                if(SPIS_1_RX_BUFFER_SIZE == locTail)
                {
                    locTail = 0u;
                }

                /* Get data fron RX software buffer */
                rxData = SPIS_1_GetWordFromRxBuffer(locTail);

                /* Change index in the buffer */
                SPIS_1_rxBufferTail = locTail;
            }
        }
        #else
        {
            rxData = SPIS_1_RX_FIFO_RD_REG; /* Read data from RX FIFO */
        }
        #endif

        return(rxData);
    }


    /*******************************************************************************
    * Function Name: SPIS_1_SpiUartGetRxBufferSize
    ********************************************************************************
    *
    * Summary:
    *  Returns the number of received data elements in the receive buffer.
    *   - RX software buffer disabled: returns the number of used entries in
    *     RX FIFO.
    *   - RX software buffer enabled: returns the number of elements which were
    *     placed in receive buffer.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Number of received data elements
    *
    *******************************************************************************/
    uint32 SPIS_1_SpiUartGetRxBufferSize(void)
    {
        uint32 size;
        #if(SPIS_1_INTERNAL_RX_SW_BUFFER_CONST)
            uint32 locHead;
        #endif /* (SPIS_1_INTERNAL_RX_SW_BUFFER_CONST) */

        #if(SPIS_1_CHECK_RX_SW_BUFFER)
        {
            locHead = SPIS_1_rxBufferHead;

            if(locHead >= SPIS_1_rxBufferTail)
            {
                size = (locHead - SPIS_1_rxBufferTail);
            }
            else
            {
                size = (locHead + (SPIS_1_RX_BUFFER_SIZE - SPIS_1_rxBufferTail));
            }
        }
        #else
        {
            size = SPIS_1_GET_RX_FIFO_ENTRIES;
        }
        #endif

        return(size);
    }


    /*******************************************************************************
    * Function Name: SPIS_1_SpiUartClearRxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Clear the receive buffer and RX FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SPIS_1_SpiUartClearRxBuffer(void)
    {
        #if(SPIS_1_INTERNAL_RX_SW_BUFFER_CONST)
            uint32 intSourceMask;
        #endif /* (SPIS_1_INTERNAL_RX_SW_BUFFER_CONST) */

        #if(SPIS_1_CHECK_RX_SW_BUFFER)
        {
            intSourceMask = SPIS_1_SpiUartDisableIntRx();

            SPIS_1_CLEAR_RX_FIFO;

            /* Flush RX software buffer */
            SPIS_1_rxBufferHead     = SPIS_1_rxBufferTail;
            SPIS_1_rxBufferOverflow = 0u;

            /* End RX transfer */
            SPIS_1_ClearRxInterruptSource(SPIS_1_INTR_RX_ALL);

            SPIS_1_SpiUartEnableIntRx(intSourceMask);
        }
        #else
        {
            SPIS_1_CLEAR_RX_FIFO;
        }
        #endif
    }

#endif /* (SPIS_1_RX_DIRECTION) */


#if(SPIS_1_TX_DIRECTION)

    /*******************************************************************************
    * Function Name: SPIS_1_SpiUartWriteTxData
    ********************************************************************************
    *
    * Summary:
    *  Places a data entry into the transmit buffer to be sent at the next available
    *  bus time.
    *  This function is blocking and waits until there is space available to put the
    *  requested data in the transmit buffer.
    *
    * Parameters:
    *  txDataByte: the data to be transmitted.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SPIS_1_SpiUartWriteTxData(uint32 txDataByte)
    {
        #if(SPIS_1_INTERNAL_TX_SW_BUFFER_CONST)
            uint32 locHead;
            uint32 intSourceMask;
        #endif /* (SPIS_1_INTERNAL_TX_SW_BUFFER_CONST) */

        #if(SPIS_1_CHECK_TX_SW_BUFFER)
        {
            /* Head index to put data */
            locHead = (SPIS_1_txBufferHead + 1u);

            /* Adjust TX software buffer index */
            if(SPIS_1_TX_BUFFER_SIZE == locHead)
            {
                locHead = 0u;
            }

            while(locHead == SPIS_1_txBufferTail)
            {
                /* Wait for space in the TX software buffer */
            }

            /* The TX software buffer has at least one room */

            if((SPIS_1_txBufferHead == SPIS_1_txBufferTail) &&
               (SPIS_1_FIFO_SIZE != SPIS_1_GET_TX_FIFO_ENTRIES))
            {
                /* TX software buffer is empty: put data directly in TX FIFO */
                SPIS_1_TX_FIFO_WR_REG = txDataByte;
            }
            /* Put data in the TX software buffer */
            else
            {
                /* Clear old status of INTR_TX_EMPTY. It sets at the end of transfer: TX FIFO empty. */
                SPIS_1_ClearTxInterruptSource(SPIS_1_INTR_TX_NOT_FULL);

                SPIS_1_PutWordInTxBuffer(locHead, txDataByte);

                SPIS_1_txBufferHead = locHead;

                /* Enable interrupt to transmit */
                intSourceMask  = SPIS_1_INTR_TX_NOT_FULL;
                intSourceMask |= SPIS_1_GetTxInterruptMode();
                SPIS_1_SpiUartEnableIntTx(intSourceMask);
            }
        }
        #else
        {
            while(SPIS_1_FIFO_SIZE == SPIS_1_GET_TX_FIFO_ENTRIES)
            {
                /* Block while TX FIFO is FULL */
            }

            SPIS_1_TX_FIFO_WR_REG = txDataByte;
        }
        #endif
    }


    /*******************************************************************************
    * Function Name: SPIS_1_SpiUartPutArray
    ********************************************************************************
    *
    * Summary:
    *  Places an array of data into the transmit buffer to be sent.
    *  This function is blocking and waits until there is a space available to put
    *  all the requested data in the transmit buffer. The array size can be greater
    *  than transmit buffer size.
    *
    * Parameters:
    *  wrBuf:  pointer to an array with data to be placed in transmit buffer.
    *  count:  number of data elements to be placed in the transmit buffer.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SPIS_1_SpiUartPutArray(const uint16 wrBuf[], uint32 count)
    {
        uint32 i;

        for(i=0u; i < count; i++)
        {
            SPIS_1_SpiUartWriteTxData((uint32) wrBuf[i]);
        }
    }


    /*******************************************************************************
    * Function Name: SPIS_1_SpiUartGetTxBufferSize
    ********************************************************************************
    *
    * Summary:
    *  Returns the number of elements currently in the transmit buffer.
    *  TX software buffer disabled: returns the number of used entries in TX FIFO.
    *  TX software buffer enabled: returns the number of elements currently used
    *  in the transmit buffer. This number does not include used entries in the
    *  TX FIFO. The transmit buffer size is zero until the TX FIFO is full.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Number of data elements ready to transmit.
    *
    *******************************************************************************/
    uint32 SPIS_1_SpiUartGetTxBufferSize(void)
    {
        uint32 size;
        #if(SPIS_1_INTERNAL_TX_SW_BUFFER_CONST)
            uint32 locTail;
        #endif /* (SPIS_1_INTERNAL_TX_SW_BUFFER_CONST) */

        #if(SPIS_1_CHECK_TX_SW_BUFFER)
        {
            /* Get current Tail index */
            locTail = SPIS_1_txBufferTail;

            if(SPIS_1_txBufferHead >= locTail)
            {
                size = (SPIS_1_txBufferHead - locTail);
            }
            else
            {
                size = (SPIS_1_txBufferHead + (SPIS_1_TX_BUFFER_SIZE - locTail));
            }
        }
        #else
        {
            size = SPIS_1_GET_TX_FIFO_ENTRIES;
        }
        #endif

        return(size);
    }


    /*******************************************************************************
    * Function Name: SPIS_1_SpiUartClearTxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Clears the transmit buffer and TX FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SPIS_1_SpiUartClearTxBuffer(void)
    {
        #if(SPIS_1_INTERNAL_TX_SW_BUFFER_CONST)
            uint32 intSourceMask;
        #endif /* (SPIS_1_INTERNAL_TX_SW_BUFFER_CONST) */

        #if(SPIS_1_CHECK_TX_SW_BUFFER)
        {
            intSourceMask = SPIS_1_SpiUartDisableIntTx();

            SPIS_1_CLEAR_TX_FIFO;

            /* Flush TX software buffer */
            SPIS_1_txBufferHead = SPIS_1_txBufferTail;

            /* End TX transfer if it is in progress */
            intSourceMask &= (uint32) ~SPIS_1_INTR_TX_NOT_FULL;

            SPIS_1_SpiUartEnableIntTx(intSourceMask);
        }
        #else
        {
            SPIS_1_CLEAR_TX_FIFO;
        }
        #endif
    }

#endif /* (SPIS_1_TX_DIRECTION) */


/*******************************************************************************
* Function Name: SPIS_1_SpiUartDisableIntRx
********************************************************************************
*
* Summary:
*  Disables RX interrupt sources.
*
* Parameters:
*  None
*
* Return:
*  Returns RX interrupt soureces enabled before function call.
*
*******************************************************************************/
uint32 SPIS_1_SpiUartDisableIntRx(void)
{
    uint32 intSource;

    intSource = SPIS_1_GetRxInterruptMode();

    SPIS_1_SetRxInterruptMode(SPIS_1_NO_INTR_SOURCES);

    return(intSource);
}


/*******************************************************************************
* Function Name: SPIS_1_SpiUartDisableIntTx
********************************************************************************
*
* Summary:
*  Disables TX interrupt sources.
*
* Parameters:
*  None
*
* Return:
*  Returns TX interrupt soureces enabled before function call.
*
*******************************************************************************/
uint32 SPIS_1_SpiUartDisableIntTx(void)
{
    uint32 intSourceMask;

    intSourceMask = SPIS_1_GetTxInterruptMode();

    SPIS_1_SetTxInterruptMode(SPIS_1_NO_INTR_SOURCES);

    return(intSourceMask);
}


#if(SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG)

    /*******************************************************************************
    * Function Name: SPIS_1_PutWordInRxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Stores byte/word into the RX buffer.
    *  Only available in Unconfigured operation mode.
    *
    * Parameters:
    *  index:      index to store data byte/word in the RX buffer.
    *  rxDataByte: byte/word to store.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SPIS_1_PutWordInRxBuffer(uint32 idx, uint32 rxDataByte)
    {
        /* Put data in the buffer */
        if(SPIS_1_ONE_BYTE_WIDTH == SPIS_1_rxDataBits)
        {
            SPIS_1_rxBuffer[idx] = ((uint8) rxDataByte);
        }
        else
        {
            SPIS_1_rxBuffer[(uint32)(idx << 1u)]      = LO8(LO16(rxDataByte));
            SPIS_1_rxBuffer[(uint32)(idx << 1u) + 1u] = HI8(LO16(rxDataByte));
        }
    }


    /*******************************************************************************
    * Function Name: SPIS_1_GetWordFromRxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Reads byte/word from RX buffer.
    *  Only available in Unconfigured operation mode.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Returns byte/word read from RX buffer.
    *
    *******************************************************************************/
    uint32 SPIS_1_GetWordFromRxBuffer(uint32 idx)
    {
        uint32 value;

        if(SPIS_1_ONE_BYTE_WIDTH == SPIS_1_rxDataBits)
        {
            value = SPIS_1_rxBuffer[idx];
        }
        else
        {
            value  = (uint32) SPIS_1_rxBuffer[(uint32)(idx << 1u)];
            value |= (uint32) ((uint32)SPIS_1_rxBuffer[(uint32)(idx << 1u) + 1u] << 8u);
        }

        return(value);
    }


    /*******************************************************************************
    * Function Name: SPIS_1_PutWordInTxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Stores byte/word into the TX buffer.
    * Only available in Unconfigured operation mode.
    *
    * Parameters:
    *  idx:        index to store data byte/word in the TX buffer.
    *  txDataByte: byte/word to store.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SPIS_1_PutWordInTxBuffer(uint32 idx, uint32 txDataByte)
    {
        /* Put data in the buffer */
        if(SPIS_1_ONE_BYTE_WIDTH == SPIS_1_txDataBits)
        {
            SPIS_1_txBuffer[idx] = ((uint8) txDataByte);
        }
        else
        {
            SPIS_1_txBuffer[(uint32)(idx << 1u)]      = LO8(LO16(txDataByte));
            SPIS_1_txBuffer[(uint32)(idx << 1u) + 1u] = HI8(LO16(txDataByte));
        }
    }


    /*******************************************************************************
    * Function Name: SPIS_1_GetWordFromTxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Reads byte/word from TX buffer.
    *  Only available in Unconfigured operation mode.
    *
    * Parameters:
    *  idx: index to get data byte/word from the TX buffer.
    *
    * Return:
    *  Returns byte/word read from TX buffer.
    *
    *******************************************************************************/
    uint32 SPIS_1_GetWordFromTxBuffer(uint32 idx)
    {
        uint32 value;

        if(SPIS_1_ONE_BYTE_WIDTH == SPIS_1_txDataBits)
        {
            value = (uint32) SPIS_1_txBuffer[idx];
        }
        else
        {
            value  = (uint32) SPIS_1_txBuffer[(uint32)(idx << 1u)];
            value |= (uint32) ((uint32) SPIS_1_txBuffer[(uint32)(idx << 1u) + 1u] << 8u);
        }

        return(value);
    }

#endif /* (SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG) */


/* [] END OF FILE */
