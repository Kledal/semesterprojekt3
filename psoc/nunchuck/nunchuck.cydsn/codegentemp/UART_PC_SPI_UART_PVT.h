/*******************************************************************************
* File Name: UART_PC_SPI_UART_PVT.h
* Version 1.20
*
* Description:
*  This private file provides constants and parameter values for the
*  SCB Component in SPI and UART modes.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_SPI_UART_PVT_UART_PC_H)
#define CY_SCB_SPI_UART_PVT_UART_PC_H

#include "UART_PC_SPI_UART.h"


/***************************************
*     Internal Global Vars
***************************************/

#if(UART_PC_INTERNAL_RX_SW_BUFFER_CONST)
    extern volatile uint32  UART_PC_rxBufferHead;
    extern volatile uint32  UART_PC_rxBufferTail;
    extern volatile uint8   UART_PC_rxBufferOverflow;
#endif /* (UART_PC_INTERNAL_RX_SW_BUFFER_CONST) */

#if(UART_PC_INTERNAL_TX_SW_BUFFER_CONST)
    extern volatile uint32  UART_PC_txBufferHead;
    extern volatile uint32  UART_PC_txBufferTail;
#endif /* (UART_PC_INTERNAL_TX_SW_BUFFER_CONST) */

#if(UART_PC_INTERNAL_RX_SW_BUFFER)
    extern volatile uint8 UART_PC_rxBufferInternal[UART_PC_RX_BUFFER_SIZE];
#endif /* (UART_PC_INTERNAL_RX_SW_BUFFER) */

#if(UART_PC_INTERNAL_TX_SW_BUFFER)
    extern volatile uint8 UART_PC_txBufferInternal[UART_PC_TX_BUFFER_SIZE];
#endif /* (UART_PC_INTERNAL_TX_SW_BUFFER) */


/***************************************
*     Private Function Prototypes
***************************************/

#if(UART_PC_SCB_MODE_SPI_CONST_CFG)
    void UART_PC_SpiInit(void);
#endif /* (UART_PC_SCB_MODE_SPI_CONST_CFG) */

#if(UART_PC_SPI_WAKE_ENABLE_CONST)
    void UART_PC_SpiSaveConfig(void);
    void UART_PC_SpiRestoreConfig(void);
#endif /* (UART_PC_SPI_WAKE_ENABLE_CONST) */

#if(UART_PC_SCB_MODE_UART_CONST_CFG)
    void UART_PC_UartInit(void);
#endif /* (UART_PC_SCB_MODE_UART_CONST_CFG) */

#if(UART_PC_UART_WAKE_ENABLE_CONST)
    void UART_PC_UartSaveConfig(void);
    void UART_PC_UartRestoreConfig(void);
#endif /* (UART_PC_UART_WAKE_ENABLE_CONST) */

/* Interrupt processing */
#define UART_PC_SpiUartEnableIntRx(intSourceMask)  UART_PC_SetRxInterruptMode(intSourceMask)
#define UART_PC_SpiUartEnableIntTx(intSourceMask)  UART_PC_SetTxInterruptMode(intSourceMask)
uint32  UART_PC_SpiUartDisableIntRx(void);
uint32  UART_PC_SpiUartDisableIntTx(void);

#endif /* (CY_SCB_SPI_UART_PVT_UART_PC_H) */


/* [] END OF FILE */
