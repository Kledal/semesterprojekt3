/*******************************************************************************
* File Name: UART_PC_SPI_UART.h
* Version 1.20
*
* Description:
*  This file provides constants and parameter values for the SCB Component in
*  SPI and UART modes.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_SPI_UART_UART_PC_H)
#define CY_SCB_SPI_UART_UART_PC_H

#include "UART_PC.h"


/***************************************
*   SPI Initial Parameter Constants
****************************************/

#define UART_PC_SPI_MODE                   (0u)
#define UART_PC_SPI_SUB_MODE               (0u)
#define UART_PC_SPI_CLOCK_MODE             (0u)
#define UART_PC_SPI_OVS_FACTOR             (16u)
#define UART_PC_SPI_MEDIAN_FILTER_ENABLE   (0u)
#define UART_PC_SPI_LATE_MISO_SAMPLE_ENABLE (0u)
#define UART_PC_SPI_RX_DATA_BITS_NUM       (8u)
#define UART_PC_SPI_TX_DATA_BITS_NUM       (8u)
#define UART_PC_SPI_WAKE_ENABLE            (0u)
#define UART_PC_SPI_BITS_ORDER             (1u)
#define UART_PC_SPI_TRANSFER_SEPARATION    (1u)
#define UART_PC_SPI_NUMBER_OF_SS_LINES     (1u)
#define UART_PC_SPI_RX_BUFFER_SIZE         (8u)
#define UART_PC_SPI_TX_BUFFER_SIZE         (8u)

#define UART_PC_SPI_INTERRUPT_MODE         (0u)

#define UART_PC_SPI_INTR_RX_MASK           (0u)
#define UART_PC_SPI_INTR_TX_MASK           (0u)

#define UART_PC_SPI_RX_TRIGGER_LEVEL       (7u)
#define UART_PC_SPI_TX_TRIGGER_LEVEL       (0u)


/***************************************
*   UART Initial Parameter Constants
****************************************/

#define UART_PC_UART_SUB_MODE              (0u)
#define UART_PC_UART_DIRECTION             (3u)
#define UART_PC_UART_DATA_BITS_NUM         (8u)
#define UART_PC_UART_PARITY_TYPE           (2u)
#define UART_PC_UART_STOP_BITS_NUM         (2u)
#define UART_PC_UART_OVS_FACTOR            (12u)
#define UART_PC_UART_IRDA_LOW_POWER        (0u)
#define UART_PC_UART_MEDIAN_FILTER_ENABLE  (0u)
#define UART_PC_UART_RETRY_ON_NACK         (0u)
#define UART_PC_UART_IRDA_POLARITY         (0u)
#define UART_PC_UART_DROP_ON_FRAME_ERR     (0u)
#define UART_PC_UART_DROP_ON_PARITY_ERR    (0u)
#define UART_PC_UART_WAKE_ENABLE           (0u)
#define UART_PC_UART_RX_BUFFER_SIZE        (8u)
#define UART_PC_UART_TX_BUFFER_SIZE        (8u)
#define UART_PC_UART_MP_MODE_ENABLE        (0u)
#define UART_PC_UART_MP_ACCEPT_ADDRESS     (0u)
#define UART_PC_UART_MP_RX_ADDRESS         (2u)
#define UART_PC_UART_MP_RX_ADDRESS_MASK    (255u)

#define UART_PC_UART_INTERRUPT_MODE        (0u)

#define UART_PC_UART_INTR_RX_MASK          (0u)
#define UART_PC_UART_INTR_TX_MASK          (0u)

#define UART_PC_UART_RX_TRIGGER_LEVEL      (7u)
#define UART_PC_UART_TX_TRIGGER_LEVEL      (0u)

/* Sources of RX errors */
#define UART_PC_INTR_RX_ERR        (UART_PC_INTR_RX_OVERFLOW    | \
                                             UART_PC_INTR_RX_UNDERFLOW   | \
                                             UART_PC_INTR_RX_FRAME_ERROR | \
                                             UART_PC_INTR_RX_PARITY_ERROR)

/* UART direction enum */
#define UART_PC_UART_RX    (1u)
#define UART_PC_UART_TX    (2u)
#define UART_PC_UART_TX_RX (3u)


/***************************************
*   Conditional Compilation Parameters
****************************************/

#if(UART_PC_SCB_MODE_UNCONFIG_CONST_CFG)

    /* Direction */
    #define UART_PC_RX_DIRECTION           (1u)
    #define UART_PC_TX_DIRECTION           (1u)
    #define UART_PC_UART_RX_DIRECTION      (1u)
    #define UART_PC_UART_TX_DIRECTION      (1u)

    /* Only external RX and TX buffer for uncofigured mode */
    #define UART_PC_INTERNAL_RX_SW_BUFFER   (0u)
    #define UART_PC_INTERNAL_TX_SW_BUFFER   (0u)

    /* Get RX and TX buffer size */
    #define UART_PC_RX_BUFFER_SIZE (UART_PC_rxBufferSize)
    #define UART_PC_TX_BUFFER_SIZE (UART_PC_txBufferSize)

    /* Return true if buffer is provided */
    #define UART_PC_CHECK_RX_SW_BUFFER (NULL != UART_PC_rxBuffer)
    #define UART_PC_CHECK_TX_SW_BUFFER (NULL != UART_PC_txBuffer)

    /* Always provide global variables to support RX and TX buffers */
    #define UART_PC_INTERNAL_RX_SW_BUFFER_CONST    (1u)
    #define UART_PC_INTERNAL_TX_SW_BUFFER_CONST    (1u)

    /* Get wakeup enable option */
    #define UART_PC_SPI_WAKE_ENABLE_CONST  (1u)
    #define UART_PC_CHECK_SPI_WAKE_ENABLE  (0u != UART_PC_scbEnableWake)
    #define UART_PC_UART_WAKE_ENABLE_CONST (1u)

#else

    /* SPI internal RX and TX buffers */
    #define UART_PC_INTERNAL_SPI_RX_SW_BUFFER  (UART_PC_SPI_RX_BUFFER_SIZE > \
                                                                                            UART_PC_FIFO_SIZE)
    #define UART_PC_INTERNAL_SPI_TX_SW_BUFFER  (UART_PC_SPI_TX_BUFFER_SIZE > \
                                                                                            UART_PC_FIFO_SIZE)

    /* UART internal RX and TX buffers */
    #define UART_PC_INTERNAL_UART_RX_SW_BUFFER  (UART_PC_UART_RX_BUFFER_SIZE > \
                                                                                            UART_PC_FIFO_SIZE)
    #define UART_PC_INTERNAL_UART_TX_SW_BUFFER  (UART_PC_UART_TX_BUFFER_SIZE > \
                                                                                            UART_PC_FIFO_SIZE)

    /* SPI Direction */
    #define UART_PC_SPI_RX_DIRECTION (1u)
    #define UART_PC_SPI_TX_DIRECTION (1u)

    /* UART Direction */
    #define UART_PC_UART_RX_DIRECTION (0u != (UART_PC_UART_DIRECTION & UART_PC_UART_RX))
    #define UART_PC_UART_TX_DIRECTION (0u != (UART_PC_UART_DIRECTION & UART_PC_UART_TX))

    /* Direction */
    #define UART_PC_RX_DIRECTION ((UART_PC_SCB_MODE_SPI_CONST_CFG) ? \
                                            (UART_PC_SPI_RX_DIRECTION) : (UART_PC_UART_RX_DIRECTION))

    #define UART_PC_TX_DIRECTION ((UART_PC_SCB_MODE_SPI_CONST_CFG) ? \
                                            (UART_PC_SPI_TX_DIRECTION) : (UART_PC_UART_TX_DIRECTION))

    /* Internal RX and TX buffer: for SPI or UART */
    #if(UART_PC_SCB_MODE_SPI_CONST_CFG)

        /* Internal SPI RX and TX buffer */
        #define UART_PC_INTERNAL_RX_SW_BUFFER  (UART_PC_INTERNAL_SPI_RX_SW_BUFFER)
        #define UART_PC_INTERNAL_TX_SW_BUFFER  (UART_PC_INTERNAL_SPI_TX_SW_BUFFER)

        /* Internal SPI RX and TX buffer size */
        #define UART_PC_RX_BUFFER_SIZE         (UART_PC_SPI_RX_BUFFER_SIZE + 1u)
        #define UART_PC_TX_BUFFER_SIZE         (UART_PC_SPI_TX_BUFFER_SIZE)

        /* Get wakeup enable option */
        #define UART_PC_SPI_WAKE_ENABLE_CONST  (0u != UART_PC_SPI_WAKE_ENABLE)
        #define UART_PC_UART_WAKE_ENABLE_CONST (0u)

    #else

        /* Internal UART RX and TX buffer */
        #define UART_PC_INTERNAL_RX_SW_BUFFER  (UART_PC_INTERNAL_UART_RX_SW_BUFFER)
        #define UART_PC_INTERNAL_TX_SW_BUFFER  (UART_PC_INTERNAL_UART_TX_SW_BUFFER)

        /* Internal UART RX and TX buffer size */
        #define UART_PC_RX_BUFFER_SIZE         (UART_PC_UART_RX_BUFFER_SIZE + 1u)
        #define UART_PC_TX_BUFFER_SIZE         (UART_PC_UART_TX_BUFFER_SIZE)

        /* Get wakeup enable option */
        #define UART_PC_SPI_WAKE_ENABLE_CONST  (0u)
        #define UART_PC_UART_WAKE_ENABLE_CONST (0u != UART_PC_UART_WAKE_ENABLE)
    #endif /* (UART_PC_SCB_MODE_SPI_CONST_CFG) */

    /* Internal RX and TX buffer: for SPI or UART. Used in conditional compilation check */
    #define UART_PC_CHECK_RX_SW_BUFFER (UART_PC_INTERNAL_RX_SW_BUFFER)
    #define UART_PC_CHECK_TX_SW_BUFFER (UART_PC_INTERNAL_TX_SW_BUFFER)

    /* Provide global variables to support RX and TX buffers */
    #define UART_PC_INTERNAL_RX_SW_BUFFER_CONST    (UART_PC_INTERNAL_RX_SW_BUFFER)
    #define UART_PC_INTERNAL_TX_SW_BUFFER_CONST    (UART_PC_INTERNAL_TX_SW_BUFFER)

    /* Wakeup for SPI */
    #define UART_PC_CHECK_SPI_WAKE_ENABLE  (UART_PC_SPI_WAKE_ENABLE_CONST)

#endif /* End (UART_PC_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Bootloader communication interface enable: NOT supported yet */
#define UART_PC_SPI_BTLDR_COMM_ENABLED   ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_UART_PC) || \
                                                    (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

#define UART_PC_UART_BTLDR_COMM_ENABLED   ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_UART_PC) || \
                                                    (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))


/***************************************
*       Type Definitions
***************************************/

/* UART_PC_SPI_INIT_STRUCT */
typedef struct
{
    uint32 mode;
    uint32 submode;
    uint32 sclkMode;
    uint32 oversample;
    uint32 enableMedianFilter;
    uint32 enableLateSampling;
    uint32 enableWake;
    uint32 rxDataBits;
    uint32 txDataBits;
    uint32 bitOrder;
    uint32 transferSeperation;
    uint32 rxBufferSize;
    uint8* rxBuffer;
    uint32 txBufferSize;
    uint8* txBuffer;
    uint32 enableInterrupt;
    uint32 rxInterruptMask;
    uint32 rxTriggerLevel;
    uint32 txInterruptMask;
    uint32 txTriggerLevel;
} UART_PC_SPI_INIT_STRUCT;

/* UART_PC_UART_INIT_STRUCT */
typedef struct
{
    uint32 mode;
    uint32 direction;
    uint32 dataBits;
    uint32 parity;
    uint32 stopBits;
    uint32 oversample;
    uint32 enableIrdaLowPower;
    uint32 enableMedianFilter;
    uint32 enableRetryNack;
    uint32 enableInvertedRx;
    uint32 dropOnParityErr;
    uint32 dropOnFrameErr;
    uint32 enableWake;
    uint32 rxBufferSize;
    uint8* rxBuffer;
    uint32 txBufferSize;
    uint8* txBuffer;
    uint32 enableMultiproc;
    uint32 multiprocAcceptAddr;
    uint32 multiprocAddr;
    uint32 multiprocAddrMask;
    uint32 enableInterrupt;
    uint32 rxInterruptMask;
    uint32 rxTriggerLevel;
    uint32 txInterruptMask;
    uint32 txTriggerLevel;
} UART_PC_UART_INIT_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

/* SPI specific functions */
#if(UART_PC_SCB_MODE_UNCONFIG_CONST_CFG)
    void UART_PC_SpiInit(const UART_PC_SPI_INIT_STRUCT *config);
#endif /* (UART_PC_SCB_MODE_UNCONFIG_CONST_CFG) */

#if(UART_PC_SCB_MODE_SPI_INC)
    void UART_PC_SpiSetActiveSlaveSelect(uint32 activeSelect);
#endif /* (UART_PC_SCB_MODE_SPI_INC) */

/* UART specific functions */
#if(UART_PC_SCB_MODE_UNCONFIG_CONST_CFG)
    void UART_PC_UartInit(const UART_PC_UART_INIT_STRUCT *config);
#endif /* (UART_PC_SCB_MODE_UNCONFIG_CONST_CFG) */

#if(UART_PC_SCB_MODE_UART_INC)
    void UART_PC_UartSetRxAddress(uint32 address);
    void UART_PC_UartSetRxAddressMask(uint32 addressMask);
#endif /* (UART_PC_SCB_MODE_UART_INC) */

/* UART RX direction APIs */
#if(UART_PC_UART_RX_DIRECTION)
    uint32 UART_PC_UartGetChar(void);
    uint32 UART_PC_UartGetByte(void);
#endif /* (UART_PC_UART_RX_DIRECTION) */

/* UART TX direction APIs */
#if(UART_PC_UART_TX_DIRECTION)
    #define UART_PC_UartPutChar(ch)    UART_PC_SpiUartWriteTxData((uint32)(ch))
    void UART_PC_UartPutString(const char8 string[]);
    void UART_PC_UartPutCRLF(uint32 txDataByte);
#endif /* (UART_PC_UART_TX_DIRECTION) */

/* Common APIs Rx direction */
#if(UART_PC_RX_DIRECTION)
    uint32 UART_PC_SpiUartReadRxData(void);
    uint32 UART_PC_SpiUartGetRxBufferSize(void);
    void   UART_PC_SpiUartClearRxBuffer(void);
#endif /* (UART_PC_RX_DIRECTION) */

/* Common APIs Tx direction */
#if(UART_PC_TX_DIRECTION)
    void   UART_PC_SpiUartWriteTxData(uint32 txData);
    void   UART_PC_SpiUartPutArray(const uint8 wrBuf[], uint32 count);
    void   UART_PC_SpiUartClearTxBuffer(void);
    uint32 UART_PC_SpiUartGetTxBufferSize(void);
#endif /* (UART_PC_TX_DIRECTION) */

CY_ISR_PROTO(UART_PC_SPI_UART_ISR);

#if(UART_PC_UART_RX_WAKEUP_IRQ)
    CY_ISR_PROTO(UART_PC_UART_WAKEUP_ISR);
#endif /* (UART_PC_UART_RX_WAKEUP_IRQ) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (UART_PC_SPI_BTLDR_COMM_ENABLED)
    /* SPI Bootloader physical layer functions */
    void UART_PC_SpiCyBtldrCommStart(void);
    void UART_PC_SpiCyBtldrCommStop (void);
    void UART_PC_SpiCyBtldrCommReset(void);
    cystatus UART_PC_SpiCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus UART_PC_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (UART_PC_SPI_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (UART_PC_UART_BTLDR_COMM_ENABLED)
    /* UART Bootloader physical layer functions */
    void UART_PC_UartCyBtldrCommStart(void);
    void UART_PC_UartCyBtldrCommStop (void);
    void UART_PC_UartCyBtldrCommReset(void);
    cystatus UART_PC_UartCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus UART_PC_UartCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (UART_PC_UART_BTLDR_COMM_ENABLED) */


/***************************************
*     Buffer Access Macro Definitions
***************************************/

#if(UART_PC_SCB_MODE_UNCONFIG_CONST_CFG)
    /* RX direction */
    void   UART_PC_PutWordInRxBuffer  (uint32 idx, uint32 rxDataByte);
    uint32 UART_PC_GetWordFromRxBuffer(uint32 idx);

    /* TX direction */
    void   UART_PC_PutWordInTxBuffer  (uint32 idx, uint32 txDataByte);
    uint32 UART_PC_GetWordFromTxBuffer(uint32 idx);

#else

    /* RX direction */
    #if(UART_PC_INTERNAL_RX_SW_BUFFER_CONST)
        #define UART_PC_PutWordInRxBuffer(idx, rxDataByte) \
                do{                                                 \
                    UART_PC_rxBufferInternal[(idx)] = ((uint8) (rxDataByte)); \
                }while(0)

        #define UART_PC_GetWordFromRxBuffer(idx) UART_PC_rxBufferInternal[(idx)]

    #endif /* (UART_PC_INTERNAL_RX_SW_BUFFER_CONST) */

    /* TX direction */
    #if(UART_PC_INTERNAL_TX_SW_BUFFER_CONST)
        #define UART_PC_PutWordInTxBuffer(idx, txDataByte) \
                    do{                                             \
                        UART_PC_txBufferInternal[(idx)] = ((uint8) (txDataByte)); \
                    }while(0)

        #define UART_PC_GetWordFromTxBuffer(idx) UART_PC_txBufferInternal[(idx)]

    #endif /* (UART_PC_INTERNAL_TX_SW_BUFFER_CONST) */

#endif /* (UART_PC_TX_SW_BUFFER_ENABLE) */


/***************************************
*         SPI API Constants
***************************************/

/* SPI mode enum */
#define UART_PC_SPI_SLAVE  (0u)
#define UART_PC_SPI_MASTER (1u)

/* SPI sub mode enum */
#define UART_PC_SPI_MODE_MOTOROLA      (0x00u)
#define UART_PC_SPI_MODE_TI_COINCIDES  (0x01u)
#define UART_PC_SPI_MODE_TI_PRECEDES   (0x11u)
#define UART_PC_SPI_MODE_NATIONAL      (0x02u)
#define UART_PC_SPI_MODE_MASK          (0x03u)
#define UART_PC_SPI_MODE_TI_PRECEDES_MASK  (0x10u)

/* SPI phase and polarity mode enum */
#define UART_PC_SPI_SCLK_CPHA0_CPOL0   (0x00u)
#define UART_PC_SPI_SCLK_CPHA0_CPOL1   (0x02u)
#define UART_PC_SPI_SCLK_CPHA1_CPOL0   (0x01u)
#define UART_PC_SPI_SCLK_CPHA1_CPOL1   (0x03u)

/* SPI bits order enum */
#define UART_PC_BITS_ORDER_LSB_FIRST   (0u)
#define UART_PC_BITS_ORDER_MSB_FIRST   (1u)

/* SPI transfer separation enum */
#define UART_PC_SPI_TRANSFER_SEPARATED     (0u)
#define UART_PC_SPI_TRANSFER_CONTINUOUS    (1u)

/* SPI master active slave select constants for UART_PC_SpiSetActiveSlaveSelect() */
#define UART_PC_SPIM_ACTIVE_SS0    (0x00u)
#define UART_PC_SPIM_ACTIVE_SS1    (0x01u)
#define UART_PC_SPIM_ACTIVE_SS2    (0x02u)
#define UART_PC_SPIM_ACTIVE_SS3    (0x03u)


/***************************************
*         UART API Constants
***************************************/

/* UART sub-modes enum */
#define UART_PC_UART_MODE_STD          (0u)
#define UART_PC_UART_MODE_SMARTCARD    (1u)
#define UART_PC_UART_MODE_IRDA         (2u)

/* UART direction enum */
#define UART_PC_UART_RX    (1u)
#define UART_PC_UART_TX    (2u)
#define UART_PC_UART_TX_RX (3u)

/* UART parity enum */
#define UART_PC_UART_PARITY_EVEN   (0u)
#define UART_PC_UART_PARITY_ODD    (1u)
#define UART_PC_UART_PARITY_NONE   (2u)

/* UART stop bits enum */
#define UART_PC_UART_STOP_BITS_1   (2u)
#define UART_PC_UART_STOP_BITS_1_5 (3u)
#define UART_PC_UART_STOP_BITS_2   (4u)

/* UART IrDA low power OVS enum */
#define UART_PC_UART_IRDA_LP_OVS16     (16u)
#define UART_PC_UART_IRDA_LP_OVS32     (32u)
#define UART_PC_UART_IRDA_LP_OVS48     (48u)
#define UART_PC_UART_IRDA_LP_OVS96     (96u)
#define UART_PC_UART_IRDA_LP_OVS192    (192u)
#define UART_PC_UART_IRDA_LP_OVS768    (768u)
#define UART_PC_UART_IRDA_LP_OVS1536   (1536u)

/* Uart MP: mark (address) and space (data) bit definitions */
#define UART_PC_UART_MP_MARK       (0x100u)
#define UART_PC_UART_MP_SPACE      (0x000u)


/***************************************
*     Vars with External Linkage
***************************************/

#if(UART_PC_SCB_MODE_UNCONFIG_CONST_CFG)
    extern const UART_PC_SPI_INIT_STRUCT  UART_PC_configSpi;
    extern const UART_PC_UART_INIT_STRUCT UART_PC_configUart;
#endif /* (UART_PC_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*    Specific SPI Macro Definitions
***************************************/

#define UART_PC_GET_SPI_INTR_SLAVE_MASK(sourceMask)  ((sourceMask) & UART_PC_INTR_SLAVE_SPI_BUS_ERROR)
#define UART_PC_GET_SPI_INTR_MASTER_MASK(sourceMask) ((sourceMask) & UART_PC_INTR_MASTER_SPI_DONE)
#define UART_PC_GET_SPI_INTR_RX_MASK(sourceMask) \
                                             ((sourceMask) & (uint32) ~UART_PC_INTR_SLAVE_SPI_BUS_ERROR)

#define UART_PC_GET_SPI_INTR_TX_MASK(sourceMask) \
                                             ((sourceMask) & (uint32) ~UART_PC_INTR_MASTER_SPI_DONE)


/***************************************
*    Specific UART Macro Definitions
***************************************/

#define UART_PC_UART_GET_CTRL_OVS_IRDA_LP(oversample) \
        ((UART_PC_UART_IRDA_LP_OVS16   == (oversample)) ? UART_PC_CTRL_OVS_IRDA_LP_OVS16 : \
         ((UART_PC_UART_IRDA_LP_OVS32   == (oversample)) ? UART_PC_CTRL_OVS_IRDA_LP_OVS32 : \
          ((UART_PC_UART_IRDA_LP_OVS48   == (oversample)) ? UART_PC_CTRL_OVS_IRDA_LP_OVS48 : \
           ((UART_PC_UART_IRDA_LP_OVS96   == (oversample)) ? UART_PC_CTRL_OVS_IRDA_LP_OVS96 : \
            ((UART_PC_UART_IRDA_LP_OVS192  == (oversample)) ? UART_PC_CTRL_OVS_IRDA_LP_OVS192 : \
             ((UART_PC_UART_IRDA_LP_OVS768  == (oversample)) ? UART_PC_CTRL_OVS_IRDA_LP_OVS768 : \
              ((UART_PC_UART_IRDA_LP_OVS1536 == (oversample)) ? UART_PC_CTRL_OVS_IRDA_LP_OVS1536 : \
                                                                          UART_PC_CTRL_OVS_IRDA_LP_OVS16)))))))

#define UART_PC_GET_UART_RX_CTRL_ENABLED(direction) ((0u != (UART_PC_UART_RX & (direction))) ? \
                                                                    (UART_PC_RX_CTRL_ENABLED) : (0u))

#define UART_PC_GET_UART_TX_CTRL_ENABLED(direction) ((0u != (UART_PC_UART_TX & (direction))) ? \
                                                                    (UART_PC_TX_CTRL_ENABLED) : (0u))


/***************************************
*        SPI Register Settings
***************************************/

#define UART_PC_CTRL_SPI      (UART_PC_CTRL_MODE_SPI)
#define UART_PC_SPI_RX_CTRL   (UART_PC_RX_CTRL_ENABLED)
#define UART_PC_SPI_TX_CTRL   (UART_PC_TX_CTRL_ENABLED)


/***************************************
*       SPI Init Register Settings
***************************************/

#if(UART_PC_SCB_MODE_SPI_CONST_CFG)

    /* SPI Configuration */
    #define UART_PC_SPI_DEFAULT_CTRL \
                    (UART_PC_GET_CTRL_OVS(UART_PC_SPI_OVS_FACTOR)         | \
                     UART_PC_GET_CTRL_EC_AM_MODE(UART_PC_SPI_WAKE_ENABLE) | \
                     UART_PC_CTRL_SPI)

    #define UART_PC_SPI_DEFAULT_SPI_CTRL \
                    (UART_PC_GET_SPI_CTRL_CONTINUOUS    (UART_PC_SPI_TRANSFER_SEPARATION)       | \
                     UART_PC_GET_SPI_CTRL_SELECT_PRECEDE(UART_PC_SPI_SUB_MODE &                   \
                                                                  UART_PC_SPI_MODE_TI_PRECEDES_MASK)     | \
                     UART_PC_GET_SPI_CTRL_SCLK_MODE     (UART_PC_SPI_CLOCK_MODE)                | \
                     UART_PC_GET_SPI_CTRL_LATE_MISO_SAMPLE(UART_PC_SPI_LATE_MISO_SAMPLE_ENABLE) | \
                     UART_PC_GET_SPI_CTRL_SUB_MODE      (UART_PC_SPI_SUB_MODE)                  | \
                     UART_PC_GET_SPI_CTRL_MASTER_MODE   (UART_PC_SPI_MODE))

    /* RX direction */
    #define UART_PC_SPI_DEFAULT_RX_CTRL \
                    (UART_PC_GET_RX_CTRL_DATA_WIDTH(UART_PC_SPI_RX_DATA_BITS_NUM)     | \
                     UART_PC_GET_RX_CTRL_BIT_ORDER (UART_PC_SPI_BITS_ORDER)           | \
                     UART_PC_GET_RX_CTRL_MEDIAN    (UART_PC_SPI_MEDIAN_FILTER_ENABLE) | \
                     UART_PC_SPI_RX_CTRL)

    #define UART_PC_SPI_DEFAULT_RX_FIFO_CTRL \
                    UART_PC_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(UART_PC_SPI_RX_TRIGGER_LEVEL)

    /* TX direction */
    #define UART_PC_SPI_DEFAULT_TX_CTRL \
                    (UART_PC_GET_TX_CTRL_DATA_WIDTH(UART_PC_SPI_TX_DATA_BITS_NUM) | \
                     UART_PC_GET_TX_CTRL_BIT_ORDER (UART_PC_SPI_BITS_ORDER)       | \
                     UART_PC_SPI_TX_CTRL)

    #define UART_PC_SPI_DEFAULT_TX_FIFO_CTRL \
                    UART_PC_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(UART_PC_SPI_TX_TRIGGER_LEVEL)

    /* Interrupt sources */
    #define UART_PC_SPI_DEFAULT_INTR_SPI_EC_MASK   (UART_PC_NO_INTR_SOURCES)

    #define UART_PC_SPI_DEFAULT_INTR_I2C_EC_MASK   (UART_PC_NO_INTR_SOURCES)
    #define UART_PC_SPI_DEFAULT_INTR_SLAVE_MASK \
                    (UART_PC_SPI_INTR_RX_MASK & UART_PC_INTR_SLAVE_SPI_BUS_ERROR)

    #define UART_PC_SPI_DEFAULT_INTR_MASTER_MASK \
                    (UART_PC_SPI_INTR_TX_MASK & UART_PC_INTR_MASTER_SPI_DONE)

    #define UART_PC_SPI_DEFAULT_INTR_RX_MASK \
                    (UART_PC_SPI_INTR_RX_MASK & (uint32) ~UART_PC_INTR_SLAVE_SPI_BUS_ERROR)

    #define UART_PC_SPI_DEFAULT_INTR_TX_MASK \
                    (UART_PC_SPI_INTR_TX_MASK & (uint32) ~UART_PC_INTR_MASTER_SPI_DONE)

#endif /* (UART_PC_SCB_MODE_SPI_CONST_CFG) */


/***************************************
*        UART Register Settings
***************************************/

#define UART_PC_CTRL_UART      (UART_PC_CTRL_MODE_UART)
#define UART_PC_UART_RX_CTRL   (UART_PC_RX_CTRL_LSB_FIRST) /* LSB for UART goes first */
#define UART_PC_UART_TX_CTRL   (UART_PC_TX_CTRL_LSB_FIRST) /* LSB for UART goes first */


/***************************************
*      UART Init Register Settings
***************************************/

#if(UART_PC_SCB_MODE_UART_CONST_CFG)

    /* UART configuration */
    #if(UART_PC_UART_MODE_IRDA == UART_PC_UART_SUB_MODE)

        #define UART_PC_DEFAULT_CTRL_OVS   ((0u != UART_PC_UART_IRDA_LOW_POWER) ?              \
                                (UART_PC_UART_GET_CTRL_OVS_IRDA_LP(UART_PC_UART_OVS_FACTOR)) : \
                                (UART_PC_CTRL_OVS_IRDA_OVS16))

    #else

        #define UART_PC_DEFAULT_CTRL_OVS   UART_PC_GET_CTRL_OVS(UART_PC_UART_OVS_FACTOR)

    #endif /* (UART_PC_UART_MODE_IRDA == UART_PC_UART_SUB_MODE) */

    #define UART_PC_UART_DEFAULT_CTRL \
                                (UART_PC_GET_CTRL_ADDR_ACCEPT(UART_PC_UART_MP_ACCEPT_ADDRESS) | \
                                 UART_PC_DEFAULT_CTRL_OVS                                              | \
                                 UART_PC_CTRL_UART)

    #define UART_PC_UART_DEFAULT_UART_CTRL \
                                    (UART_PC_GET_UART_CTRL_MODE(UART_PC_UART_SUB_MODE))

    /* RX direction */
    #define UART_PC_UART_DEFAULT_RX_CTRL_PARITY \
                                ((UART_PC_UART_PARITY_NONE != UART_PC_UART_PARITY_TYPE) ?      \
                                  (UART_PC_GET_UART_RX_CTRL_PARITY(UART_PC_UART_PARITY_TYPE) | \
                                   UART_PC_UART_RX_CTRL_PARITY_ENABLED) : (0u))

    #define UART_PC_UART_DEFAULT_UART_RX_CTRL \
                    (UART_PC_GET_UART_RX_CTRL_MODE(UART_PC_UART_STOP_BITS_NUM)                    | \
                     UART_PC_GET_UART_RX_CTRL_POLARITY(UART_PC_UART_IRDA_POLARITY)                | \
                     UART_PC_GET_UART_RX_CTRL_MP_MODE(UART_PC_UART_MP_MODE_ENABLE)                | \
                     UART_PC_GET_UART_RX_CTRL_DROP_ON_PARITY_ERR(UART_PC_UART_DROP_ON_PARITY_ERR) | \
                     UART_PC_GET_UART_RX_CTRL_DROP_ON_FRAME_ERR(UART_PC_UART_DROP_ON_FRAME_ERR)   | \
                     UART_PC_UART_DEFAULT_RX_CTRL_PARITY)

    #define UART_PC_UART_DEFAULT_RX_CTRL \
                                (UART_PC_GET_RX_CTRL_DATA_WIDTH(UART_PC_UART_DATA_BITS_NUM)        | \
                                 UART_PC_GET_RX_CTRL_MEDIAN    (UART_PC_UART_MEDIAN_FILTER_ENABLE) | \
                                 UART_PC_GET_UART_RX_CTRL_ENABLED(UART_PC_UART_DIRECTION))

    #define UART_PC_UART_DEFAULT_RX_FIFO_CTRL \
                                UART_PC_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(UART_PC_UART_RX_TRIGGER_LEVEL)

    #define UART_PC_UART_DEFAULT_RX_MATCH_REG  ((0u != UART_PC_UART_MP_MODE_ENABLE) ?          \
                                (UART_PC_GET_RX_MATCH_ADDR(UART_PC_UART_MP_RX_ADDRESS) | \
                                 UART_PC_GET_RX_MATCH_MASK(UART_PC_UART_MP_RX_ADDRESS_MASK)) : (0u))

    /* TX direction */
    #define UART_PC_UART_DEFAULT_TX_CTRL_PARITY (UART_PC_UART_DEFAULT_RX_CTRL_PARITY)

    #define UART_PC_UART_DEFAULT_UART_TX_CTRL \
                                (UART_PC_GET_UART_TX_CTRL_MODE(UART_PC_UART_STOP_BITS_NUM)       | \
                                 UART_PC_GET_UART_TX_CTRL_RETRY_NACK(UART_PC_UART_RETRY_ON_NACK) | \
                                 UART_PC_UART_DEFAULT_TX_CTRL_PARITY)

    #define UART_PC_UART_DEFAULT_TX_CTRL \
                                (UART_PC_GET_TX_CTRL_DATA_WIDTH(UART_PC_UART_DATA_BITS_NUM) | \
                                 UART_PC_GET_UART_TX_CTRL_ENABLED(UART_PC_UART_DIRECTION))

    #define UART_PC_UART_DEFAULT_TX_FIFO_CTRL \
                                UART_PC_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(UART_PC_UART_TX_TRIGGER_LEVEL)

    /* Interrupt sources */
    #define UART_PC_UART_DEFAULT_INTR_I2C_EC_MASK  (UART_PC_NO_INTR_SOURCES)
    #define UART_PC_UART_DEFAULT_INTR_SPI_EC_MASK  (UART_PC_NO_INTR_SOURCES)
    #define UART_PC_UART_DEFAULT_INTR_SLAVE_MASK   (UART_PC_NO_INTR_SOURCES)
    #define UART_PC_UART_DEFAULT_INTR_MASTER_MASK  (UART_PC_NO_INTR_SOURCES)
    #define UART_PC_UART_DEFAULT_INTR_RX_MASK      (UART_PC_UART_INTR_RX_MASK)
    #define UART_PC_UART_DEFAULT_INTR_TX_MASK      (UART_PC_UART_INTR_TX_MASK)

#endif /* (UART_PC_SCB_MODE_UART_CONST_CFG) */

#endif /* CY_SCB_SPI_UART_UART_PC_H */


/* [] END OF FILE */
