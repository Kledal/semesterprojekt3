/*******************************************************************************
* File Name: SPIS_1_SPI_UART.h
* Version 1.10
*
* Description:
*  This file provides constants and parameter values for the SCB Component in
*  SPI and UART modes.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_SPI_UART_SPIS_1_H)
#define CY_SCB_SPI_UART_SPIS_1_H

#include "SPIS_1.h"


/***************************************
*   SPI Initial Parameter Constants
****************************************/

#define SPIS_1_SPI_MODE                   (0u)
#define SPIS_1_SPI_SUB_MODE               (0u)
#define SPIS_1_SPI_CLOCK_MODE             (3u)
#define SPIS_1_SPI_OVS_FACTOR             (12u)
#define SPIS_1_SPI_MEDIAN_FILTER_ENABLE   (0u)
#define SPIS_1_SPI_LATE_MISO_SAMPLE_ENABLE (0u)
#define SPIS_1_SPI_RX_DATA_BITS_NUM       (16u)
#define SPIS_1_SPI_TX_DATA_BITS_NUM       (16u)
#define SPIS_1_SPI_WAKE_ENABLE            (0u)
#define SPIS_1_SPI_BITS_ORDER             (1u)
#define SPIS_1_SPI_TRANSFER_SEPARATION    (1u)
#define SPIS_1_SPI_NUMBER_OF_SS_LINES     (1u)
#define SPIS_1_SPI_RX_BUFFER_SIZE         (8u)
#define SPIS_1_SPI_TX_BUFFER_SIZE         (8u)

#define SPIS_1_SPI_INTERRUPT_MODE         (1u)

#define SPIS_1_SPI_INTR_RX_MASK           (12u)
#define SPIS_1_SPI_INTR_TX_MASK           (0u)

#define SPIS_1_SPI_RX_TRIGGER_LEVEL       (7u)
#define SPIS_1_SPI_TX_TRIGGER_LEVEL       (0u)


/***************************************
*   UART Initial Parameter Constants
****************************************/

#define SPIS_1_UART_SUB_MODE              (0u)
#define SPIS_1_UART_DIRECTION             (3u)
#define SPIS_1_UART_DATA_BITS_NUM         (8u)
#define SPIS_1_UART_PARITY_TYPE           (2u)
#define SPIS_1_UART_STOP_BITS_NUM         (2u)
#define SPIS_1_UART_OVS_FACTOR            (12u)
#define SPIS_1_UART_IRDA_LOW_POWER        (0u)
#define SPIS_1_UART_MEDIAN_FILTER_ENABLE  (0u)
#define SPIS_1_UART_RETRY_ON_NACK         (0u)
#define SPIS_1_UART_IRDA_POLARITY         (0u)
#define SPIS_1_UART_DROP_ON_FRAME_ERR     (0u)
#define SPIS_1_UART_DROP_ON_PARITY_ERR    (0u)
#define SPIS_1_UART_WAKE_ENABLE           (0u)
#define SPIS_1_UART_RX_BUFFER_SIZE        (8u)
#define SPIS_1_UART_TX_BUFFER_SIZE        (8u)
#define SPIS_1_UART_MP_MODE_ENABLE        (0u)
#define SPIS_1_UART_MP_ACCEPT_ADDRESS     (0u)
#define SPIS_1_UART_MP_RX_ADDRESS         (2u)
#define SPIS_1_UART_MP_RX_ADDRESS_MASK    (255u)

#define SPIS_1_UART_INTERRUPT_MODE        (0u)

#define SPIS_1_UART_INTR_RX_MASK          (4u)
#define SPIS_1_UART_INTR_TX_MASK          (0u)

#define SPIS_1_UART_RX_TRIGGER_LEVEL      (7u)
#define SPIS_1_UART_TX_TRIGGER_LEVEL      (0u)

/* Sources of RX errors */
#define SPIS_1_INTR_RX_ERR        (SPIS_1_INTR_RX_OVERFLOW    | \
                                             SPIS_1_INTR_RX_UNDERFLOW   | \
                                             SPIS_1_INTR_RX_FRAME_ERROR | \
                                             SPIS_1_INTR_RX_PARITY_ERROR)

/* UART direction enum */
#define SPIS_1_UART_RX    (1u)
#define SPIS_1_UART_TX    (2u)
#define SPIS_1_UART_TX_RX (3u)


/***************************************
*   Conditional Compilation Parameters
****************************************/

#if(SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG)

    /* Direction */
    #define SPIS_1_RX_DIRECTION           (1u)
    #define SPIS_1_TX_DIRECTION           (1u)
    #define SPIS_1_UART_RX_DIRECTION      (1u)
    #define SPIS_1_UART_TX_DIRECTION      (1u)

    /* Only external RX and TX buffer for uncofigured mode */
    #define SPIS_1_INTERNAL_RX_SW_BUFFER   (0u)
    #define SPIS_1_INTERNAL_TX_SW_BUFFER   (0u)

    /* Get RX and TX buffer size */
    #define SPIS_1_RX_BUFFER_SIZE (SPIS_1_rxBufferSize)
    #define SPIS_1_TX_BUFFER_SIZE (SPIS_1_txBufferSize)

    /* Return true if buffer is provided */
    #define SPIS_1_CHECK_RX_SW_BUFFER (NULL != SPIS_1_rxBuffer)
    #define SPIS_1_CHECK_TX_SW_BUFFER (NULL != SPIS_1_txBuffer)

    /* Alwasy provde global variables to support RX and TX buffers */
    #define SPIS_1_INTERNAL_RX_SW_BUFFER_CONST    (1u)
    #define SPIS_1_INTERNAL_TX_SW_BUFFER_CONST    (1u)

    /* Get wakeup enable option */
    #define SPIS_1_SPI_WAKE_ENABLE_CONST  (1u)
    #define SPIS_1_CHECK_SPI_WAKE_ENABLE  (0u != SPIS_1_scbEnableWake)
    #define SPIS_1_UART_WAKE_ENABLE_CONST (1u)

#else

    /* SPI internal RX and TX buffers */
    #define SPIS_1_INTERNAL_SPI_RX_SW_BUFFER  (SPIS_1_SPI_RX_BUFFER_SIZE > \
                                                                                            SPIS_1_FIFO_SIZE)
    #define SPIS_1_INTERNAL_SPI_TX_SW_BUFFER  (SPIS_1_SPI_TX_BUFFER_SIZE > \
                                                                                            SPIS_1_FIFO_SIZE)

    /* UART internal RX and TX buffers */
    #define SPIS_1_INTERNAL_UART_RX_SW_BUFFER  (SPIS_1_UART_RX_BUFFER_SIZE > \
                                                                                            SPIS_1_FIFO_SIZE)
    #define SPIS_1_INTERNAL_UART_TX_SW_BUFFER  (SPIS_1_UART_TX_BUFFER_SIZE > \
                                                                                            SPIS_1_FIFO_SIZE)

    /* SPI Direction */
    #define SPIS_1_SPI_RX_DIRECTION (1u)
    #define SPIS_1_SPI_TX_DIRECTION (1u)

    /* UART Direction */
    #define SPIS_1_UART_RX_DIRECTION (0u != (SPIS_1_UART_DIRECTION & SPIS_1_UART_RX))
    #define SPIS_1_UART_TX_DIRECTION (0u != (SPIS_1_UART_DIRECTION & SPIS_1_UART_TX))

    /* Direction */
    #define SPIS_1_RX_DIRECTION ((SPIS_1_SCB_MODE_SPI_CONST_CFG) ? \
                                            (SPIS_1_SPI_RX_DIRECTION) : (SPIS_1_UART_RX_DIRECTION))

    #define SPIS_1_TX_DIRECTION ((SPIS_1_SCB_MODE_SPI_CONST_CFG) ? \
                                            (SPIS_1_SPI_TX_DIRECTION) : (SPIS_1_UART_TX_DIRECTION))

    /* Internal RX and TX buffer: for SPI or UART */
    #if(SPIS_1_SCB_MODE_SPI_CONST_CFG)

        /* Internal SPI RX and TX buffer */
        #define SPIS_1_INTERNAL_RX_SW_BUFFER  (SPIS_1_INTERNAL_SPI_RX_SW_BUFFER)
        #define SPIS_1_INTERNAL_TX_SW_BUFFER  (SPIS_1_INTERNAL_SPI_TX_SW_BUFFER)

        /* Internal SPI RX and TX buffer size */
        #define SPIS_1_RX_BUFFER_SIZE         (SPIS_1_SPI_RX_BUFFER_SIZE + 1u)
        #define SPIS_1_TX_BUFFER_SIZE         (SPIS_1_SPI_TX_BUFFER_SIZE)
        
        /* Get wakeup enable option */
        #define SPIS_1_SPI_WAKE_ENABLE_CONST  (0u != SPIS_1_SPI_WAKE_ENABLE)
        #define SPIS_1_UART_WAKE_ENABLE_CONST (0u)

    #else

        /* Internal UART RX and TX buffer */
        #define SPIS_1_INTERNAL_RX_SW_BUFFER  (SPIS_1_INTERNAL_UART_RX_SW_BUFFER)
        #define SPIS_1_INTERNAL_TX_SW_BUFFER  (SPIS_1_INTERNAL_UART_TX_SW_BUFFER)

        /* Internal UART RX and TX buffer size */
        #define SPIS_1_RX_BUFFER_SIZE         (SPIS_1_UART_RX_BUFFER_SIZE + 1u)
        #define SPIS_1_TX_BUFFER_SIZE         (SPIS_1_UART_TX_BUFFER_SIZE)
        
        /* Get wakeup enable option */
        #define SPIS_1_SPI_WAKE_ENABLE_CONST  (0u)
        #define SPIS_1_UART_WAKE_ENABLE_CONST (0u != SPIS_1_UART_WAKE_ENABLE)
    #endif /* (SPIS_1_SCB_MODE_SPI_CONST_CFG) */

    /* Internal RX and TX buffer: for SPI or UART. Used in conditional compilation check */
    #define SPIS_1_CHECK_RX_SW_BUFFER (SPIS_1_INTERNAL_RX_SW_BUFFER)
    #define SPIS_1_CHECK_TX_SW_BUFFER (SPIS_1_INTERNAL_TX_SW_BUFFER)

    /* Provide global variables to support RX and TX buffers */
    #define SPIS_1_INTERNAL_RX_SW_BUFFER_CONST    (SPIS_1_INTERNAL_RX_SW_BUFFER)
    #define SPIS_1_INTERNAL_TX_SW_BUFFER_CONST    (SPIS_1_INTERNAL_TX_SW_BUFFER)
    
    /* Wakeup for SPI */
    #define SPIS_1_CHECK_SPI_WAKE_ENABLE  (SPIS_1_SPI_WAKE_ENABLE_CONST)

#endif /* End (SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Bootloader communication interface enable: NOT supported yet */
#define SPIS_1_SPI_BTLDR_COMM_ENABLED   ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SPIS_1) || \
                                                    (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

#define SPIS_1_UART_BTLDR_COMM_ENABLED   ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SPIS_1) || \
                                                    (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))


/***************************************
*       Type Definitions
***************************************/

/* SPIS_1_SPI_INIT_STRUCT */
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
} SPIS_1_SPI_INIT_STRUCT;

/* SPIS_1_UART_INIT_STRUCT */
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
} SPIS_1_UART_INIT_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

/* SPI specific functions */
#if(SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG)
    void SPIS_1_SpiInit(const SPIS_1_SPI_INIT_STRUCT *config);
#endif /* (SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG) */

#if(SPIS_1_SCB_MODE_SPI_INC)
    void SPIS_1_SpiSetActiveSlaveSelect(uint32 activeSelect);
#endif /* (SPIS_1_SCB_MODE_SPI_INC) */

/* UART specific functions */
#if(SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG)
    void SPIS_1_UartInit(const SPIS_1_UART_INIT_STRUCT *config);
#endif /* (SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG) */

#if(SPIS_1_SCB_MODE_UART_INC)
    void SPIS_1_UartSetRxAddress(uint32 address);
    void SPIS_1_UartSetRxAddressMask(uint32 addressMask);
#endif /* (SPIS_1_SCB_MODE_UART_INC) */

/* UART RX direction APIs */
#if(SPIS_1_UART_RX_DIRECTION)
    uint32 SPIS_1_UartGetChar(void);
    uint32 SPIS_1_UartGetByte(void);
#endif /* (SPIS_1_UART_RX_DIRECTION) */

/* UART TX direction APIs */
#if(SPIS_1_UART_TX_DIRECTION)
    #define SPIS_1_UartPutChar(ch)    SPIS_1_SpiUartWriteTxData((uint32)(ch))
    void SPIS_1_UartPutString(const char8 string[]);
    void SPIS_1_UartPutCRLF(uint32 txDataByte);
#endif /* (SPIS_1_UART_TX_DIRECTION) */

/* Common APIs Rx direction */
#if(SPIS_1_RX_DIRECTION)
    uint32 SPIS_1_SpiUartReadRxData(void);
    uint32 SPIS_1_SpiUartGetRxBufferSize(void);
    void   SPIS_1_SpiUartClearRxBuffer(void);
#endif /* (SPIS_1_RX_DIRECTION) */

/* Common APIs Tx direction */
#if(SPIS_1_TX_DIRECTION)
    void   SPIS_1_SpiUartWriteTxData(uint32 txDataByte);
    void   SPIS_1_SpiUartPutArray(const uint16 wrBuf[], uint32 count);
    void   SPIS_1_SpiUartClearTxBuffer(void);
    uint32 SPIS_1_SpiUartGetTxBufferSize(void);
#endif /* (SPIS_1_TX_DIRECTION) */

CY_ISR_PROTO(SPIS_1_SPI_UART_ISR);

#if(SPIS_1_UART_RX_WAKEUP_IRQ)
    CY_ISR_PROTO(SPIS_1_UART_WAKEUP_ISR);
#endif /* (SPIS_1_UART_RX_WAKEUP_IRQ) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPIS_1_SPI_BTLDR_COMM_ENABLED)
    /* SPI Bootloader physical layer functions */
    void SPIS_1_SpiCyBtldrCommStart(void);
    void SPIS_1_SpiCyBtldrCommStop (void);
    void SPIS_1_SpiCyBtldrCommReset(void);
    cystatus SPIS_1_SpiCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus SPIS_1_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPIS_1_SPI_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPIS_1_UART_BTLDR_COMM_ENABLED)
    /* UART Bootloader physical layer functions */
    void SPIS_1_UartCyBtldrCommStart(void);
    void SPIS_1_UartCyBtldrCommStop (void);
    void SPIS_1_UartCyBtldrCommReset(void);
    cystatus SPIS_1_UartCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus SPIS_1_UartCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPIS_1_UART_BTLDR_COMM_ENABLED) */


/***************************************
*     Buffer Access Macro Definitions
***************************************/

#if(SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG)
    /* RX direction */
    void   SPIS_1_PutWordInRxBuffer  (uint32 idx, uint32 rxDataByte);
    uint32 SPIS_1_GetWordFromRxBuffer(uint32 idx);

    /* TX direction */
    void   SPIS_1_PutWordInTxBuffer  (uint32 idx, uint32 txDataByte);
    uint32 SPIS_1_GetWordFromTxBuffer(uint32 idx);

#else

    /* RX direction */
    #if(SPIS_1_INTERNAL_RX_SW_BUFFER_CONST)
        #define SPIS_1_PutWordInRxBuffer(idx, rxDataByte) \
                do{                                                 \
                    SPIS_1_rxBufferInternal[(idx)] = ((uint16) (rxDataByte)); \
                }while(0)

        #define SPIS_1_GetWordFromRxBuffer(idx) SPIS_1_rxBufferInternal[(idx)]

    #endif /* (SPIS_1_INTERNAL_RX_SW_BUFFER_CONST) */

    /* TX direction */
    #if(SPIS_1_INTERNAL_TX_SW_BUFFER_CONST)
        #define SPIS_1_PutWordInTxBuffer(idx, txDataByte) \
                    do{                                             \
                        SPIS_1_txBufferInternal[(idx)] = ((uint16) (txDataByte)); \
                    }while(0)

        #define SPIS_1_GetWordFromTxBuffer(idx) SPIS_1_txBufferInternal[(idx)]

    #endif /* (SPIS_1_INTERNAL_TX_SW_BUFFER_CONST) */

#endif /* (SPIS_1_TX_SW_BUFFER_ENABLE) */


/***************************************
*         SPI API Constants
***************************************/

/* SPI mode enum */
#define SPIS_1_SPI_SLAVE  (0u)
#define SPIS_1_SPI_MASTER (1u)

/* SPI sub mode enum */
#define SPIS_1_SPI_MODE_MOTOROLA      (0x00u)
#define SPIS_1_SPI_MODE_TI_COINCIDES  (0x01u)
#define SPIS_1_SPI_MODE_TI_PRECEDES   (0x11u)
#define SPIS_1_SPI_MODE_NATIONAL      (0x02u)
#define SPIS_1_SPI_MODE_MASK          (0x03u)
#define SPIS_1_SPI_MODE_TI_PRECEDES_MASK  (0x10u)

/* SPI phase and polarity mode enum */
#define SPIS_1_SPI_SCLK_CPHA0_CPOL0   (0x00u)
#define SPIS_1_SPI_SCLK_CPHA0_CPOL1   (0x02u)
#define SPIS_1_SPI_SCLK_CPHA1_CPOL0   (0x01u)
#define SPIS_1_SPI_SCLK_CPHA1_CPOL1   (0x03u)

/* SPI bits order enum */
#define SPIS_1_BITS_ORDER_LSB_FIRST   (0u)
#define SPIS_1_BITS_ORDER_MSB_FIRST   (1u)

/* SPI transfer separation enum */
#define SPIS_1_SPI_TRANSFER_SEPARATED     (0u)
#define SPIS_1_SPI_TRANSFER_CONTINUOUS    (1u)

/* "activeSS" constants for SpiSetActiveSlaveSelect() function */
#define SPIS_1_SPIM_ACTIVE_SS0    (0x00u)
#define SPIS_1_SPIM_ACTIVE_SS1    (0x01u)
#define SPIS_1_SPIM_ACTIVE_SS2    (0x02u)
#define SPIS_1_SPIM_ACTIVE_SS3    (0x03u)


/***************************************
*         UART API Constants
***************************************/

/* UART sub-modes enum */
#define SPIS_1_UART_MODE_STD          (0u)
#define SPIS_1_UART_MODE_SMARTCARD    (1u)
#define SPIS_1_UART_MODE_IRDA         (2u)

/* UART direction enum */
#define SPIS_1_UART_RX    (1u)
#define SPIS_1_UART_TX    (2u)
#define SPIS_1_UART_TX_RX (3u)

/* UART parity enum */
#define SPIS_1_UART_PARITY_EVEN   (0u)
#define SPIS_1_UART_PARITY_ODD    (1u)
#define SPIS_1_UART_PARITY_NONE   (2u)

/* UART stop bits enum */
#define SPIS_1_UART_STOP_BITS_1   (1u)
#define SPIS_1_UART_STOP_BITS_1_5 (2u)
#define SPIS_1_UART_STOP_BITS_2   (3u)

/* UART IrDA low power OVS enum */
#define SPIS_1_UART_IRDA_LP_OVS16     (16u)
#define SPIS_1_UART_IRDA_LP_OVS32     (32u)
#define SPIS_1_UART_IRDA_LP_OVS48     (48u)
#define SPIS_1_UART_IRDA_LP_OVS96     (96u)
#define SPIS_1_UART_IRDA_LP_OVS192    (192u)
#define SPIS_1_UART_IRDA_LP_OVS768    (768u)
#define SPIS_1_UART_IRDA_LP_OVS1536   (1536u)

/* Uart MP: mark (address) and space (data) bit definitions */
#define SPIS_1_UART_MP_MARK       (0x100u)
#define SPIS_1_UART_MP_SPACE      (0x000u)


/***************************************
*     Vars with External Linkage
***************************************/

#if(SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG)
    extern const SPIS_1_SPI_INIT_STRUCT  SPIS_1_configSpi;
    extern const SPIS_1_UART_INIT_STRUCT SPIS_1_configUart;
#endif /* (SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*    Specific SPI Macro Definitions
***************************************/

#define SPIS_1_GET_SPI_INTR_SLAVE_MASK(sourceMask)  ((sourceMask) & SPIS_1_INTR_SLAVE_SPI_BUS_ERROR)
#define SPIS_1_GET_SPI_INTR_MASTER_MASK(sourceMask) ((sourceMask) & SPIS_1_INTR_MASTER_SPI_DONE)
#define SPIS_1_GET_SPI_INTR_RX_MASK(sourceMask) \
                                             ((sourceMask) & (uint32) ~SPIS_1_INTR_SLAVE_SPI_BUS_ERROR)

#define SPIS_1_GET_SPI_INTR_TX_MASK(sourceMask) \
                                             ((sourceMask) & (uint32) ~SPIS_1_INTR_MASTER_SPI_DONE)


/***************************************
*    Specific UART Macro Definitions
***************************************/

#define SPIS_1_UART_GET_CTRL_OVS_IRDA_LP(oversample) \
        ((SPIS_1_UART_IRDA_LP_OVS16   == (oversample)) ? SPIS_1_CTRL_OVS_IRDA_LP_OVS16 : \
         ((SPIS_1_UART_IRDA_LP_OVS32   == (oversample)) ? SPIS_1_CTRL_OVS_IRDA_LP_OVS32 : \
          ((SPIS_1_UART_IRDA_LP_OVS48   == (oversample)) ? SPIS_1_CTRL_OVS_IRDA_LP_OVS48 : \
           ((SPIS_1_UART_IRDA_LP_OVS96   == (oversample)) ? SPIS_1_CTRL_OVS_IRDA_LP_OVS96 : \
            ((SPIS_1_UART_IRDA_LP_OVS192  == (oversample)) ? SPIS_1_CTRL_OVS_IRDA_LP_OVS192 : \
             ((SPIS_1_UART_IRDA_LP_OVS768  == (oversample)) ? SPIS_1_CTRL_OVS_IRDA_LP_OVS768 : \
              ((SPIS_1_UART_IRDA_LP_OVS1536 == (oversample)) ? SPIS_1_CTRL_OVS_IRDA_LP_OVS1536 : \
                                                                          SPIS_1_CTRL_OVS_IRDA_LP_OVS16)))))))

#define SPIS_1_GET_UART_RX_CTRL_ENABLED(direction) ((0u != (SPIS_1_UART_RX & (direction))) ? \
                                                                    (SPIS_1_RX_CTRL_ENABLED) : (0u))

#define SPIS_1_GET_UART_TX_CTRL_ENABLED(direction) ((0u != (SPIS_1_UART_TX & (direction))) ? \
                                                                    (SPIS_1_TX_CTRL_ENABLED) : (0u))


/***************************************
*        SPI Register Settings
***************************************/

#define SPIS_1_CTRL_SPI      (SPIS_1_CTRL_MODE_SPI)
#define SPIS_1_SPI_RX_CTRL   (SPIS_1_RX_CTRL_ENABLED)
#define SPIS_1_SPI_TX_CTRL   (SPIS_1_TX_CTRL_ENABLED)


/***************************************
*       SPI Init Register Settings
***************************************/

#if(SPIS_1_SCB_MODE_SPI_CONST_CFG)

    /* SPI Configuration */
    #define SPIS_1_SPI_DEFAULT_CTRL \
                    (SPIS_1_GET_CTRL_OVS(SPIS_1_SPI_OVS_FACTOR)         | \
                     SPIS_1_GET_CTRL_EC_AM_MODE(SPIS_1_SPI_WAKE_ENABLE) | \
                     SPIS_1_CTRL_SPI)

    #define SPIS_1_SPI_DEFAULT_SPI_CTRL \
                    (SPIS_1_GET_SPI_CTRL_CONTINUOUS    (SPIS_1_SPI_TRANSFER_SEPARATION)       | \
                     SPIS_1_GET_SPI_CTRL_SELECT_PRECEDE(SPIS_1_SPI_SUB_MODE &                   \
                                                                  SPIS_1_SPI_MODE_TI_PRECEDES_MASK)     | \
                     SPIS_1_GET_SPI_CTRL_SCLK_MODE     (SPIS_1_SPI_CLOCK_MODE)                | \
                     SPIS_1_GET_SPI_CTRL_LATE_MISO_SAMPLE(SPIS_1_SPI_LATE_MISO_SAMPLE_ENABLE) | \
                     SPIS_1_GET_SPI_CTRL_SUB_MODE      (SPIS_1_SPI_SUB_MODE)                  | \
                     SPIS_1_GET_SPI_CTRL_MASTER_MODE   (SPIS_1_SPI_MODE))

    /* RX direction */
    #define SPIS_1_SPI_DEFAULT_RX_CTRL \
                    (SPIS_1_GET_RX_CTRL_DATA_WIDTH(SPIS_1_SPI_RX_DATA_BITS_NUM)     | \
                     SPIS_1_GET_RX_CTRL_BIT_ORDER (SPIS_1_SPI_BITS_ORDER)           | \
                     SPIS_1_GET_RX_CTRL_MEDIAN    (SPIS_1_SPI_MEDIAN_FILTER_ENABLE) | \
                     SPIS_1_SPI_RX_CTRL)

    #define SPIS_1_SPI_DEFAULT_RX_FIFO_CTRL \
                    SPIS_1_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(SPIS_1_SPI_RX_TRIGGER_LEVEL)

    /* TX direction */
    #define SPIS_1_SPI_DEFAULT_TX_CTRL \
                    (SPIS_1_GET_TX_CTRL_DATA_WIDTH(SPIS_1_SPI_TX_DATA_BITS_NUM) | \
                     SPIS_1_GET_TX_CTRL_BIT_ORDER (SPIS_1_SPI_BITS_ORDER)       | \
                     SPIS_1_SPI_TX_CTRL)

    #define SPIS_1_SPI_DEFAULT_TX_FIFO_CTRL \
                    SPIS_1_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(SPIS_1_SPI_TX_TRIGGER_LEVEL)

    /* Interrupt sources */
    #define SPIS_1_SPI_DEFAULT_INTR_SPI_EC_MASK   (SPIS_1_NO_INTR_SOURCES)

    #define SPIS_1_SPI_DEFAULT_INTR_I2C_EC_MASK   (SPIS_1_NO_INTR_SOURCES)
    #define SPIS_1_SPI_DEFAULT_INTR_SLAVE_MASK \
                    (SPIS_1_SPI_INTR_RX_MASK & SPIS_1_INTR_SLAVE_SPI_BUS_ERROR)

    #define SPIS_1_SPI_DEFAULT_INTR_MASTER_MASK \
                    (SPIS_1_SPI_INTR_TX_MASK & SPIS_1_INTR_MASTER_SPI_DONE)

    #define SPIS_1_SPI_DEFAULT_INTR_RX_MASK \
                    (SPIS_1_SPI_INTR_RX_MASK & (uint32) ~SPIS_1_INTR_SLAVE_SPI_BUS_ERROR)

    #define SPIS_1_SPI_DEFAULT_INTR_TX_MASK \
                    (SPIS_1_SPI_INTR_TX_MASK & (uint32) ~SPIS_1_INTR_MASTER_SPI_DONE)

#endif /* (SPIS_1_SCB_MODE_SPI_CONST_CFG) */


/***************************************
*        UART Register Settings
***************************************/

#define SPIS_1_CTRL_UART      (SPIS_1_CTRL_MODE_UART)
#define SPIS_1_UART_RX_CTRL   (SPIS_1_RX_CTRL_LSB_FIRST) /* LSB for UART goes first */
#define SPIS_1_UART_TX_CTRL   (SPIS_1_TX_CTRL_LSB_FIRST) /* LSB for UART goes first */


/***************************************
*      UART Init Register Settings
***************************************/

#if(SPIS_1_SCB_MODE_UART_CONST_CFG)

    /* UART configuration */
    #if(SPIS_1_UART_MODE_IRDA == SPIS_1_UART_SUB_MODE)

        #define SPIS_1_DEFAULT_CTRL_OVS   ((0u != SPIS_1_UART_IRDA_LOW_POWER) ?              \
                                (SPIS_1_UART_GET_CTRL_OVS_IRDA_LP(SPIS_1_UART_OVS_FACTOR)) : \
                                (SPIS_1_CTRL_OVS_IRDA_OVS16))

    #else

        #define SPIS_1_DEFAULT_CTRL_OVS   SPIS_1_GET_CTRL_OVS(SPIS_1_UART_OVS_FACTOR)

    #endif /* (SPIS_1_UART_MODE_IRDA == SPIS_1_UART_SUB_MODE) */

    #define SPIS_1_UART_DEFAULT_CTRL \
                                (SPIS_1_GET_CTRL_ADDR_ACCEPT(SPIS_1_UART_MP_ACCEPT_ADDRESS) | \
                                 SPIS_1_DEFAULT_CTRL_OVS                                              | \
                                 SPIS_1_CTRL_UART)

    #define SPIS_1_UART_DEFAULT_UART_CTRL \
                                    (SPIS_1_GET_UART_CTRL_MODE(SPIS_1_UART_SUB_MODE))

    /* RX direction */
    #define SPIS_1_UART_DEFAULT_RX_CTRL_PARITY \
                                ((SPIS_1_UART_PARITY_NONE != SPIS_1_UART_PARITY_TYPE) ?      \
                                  (SPIS_1_GET_UART_RX_CTRL_PARITY(SPIS_1_UART_PARITY_TYPE) | \
                                   SPIS_1_UART_RX_CTRL_PARITY_ENABLED) : (0u))

    #define SPIS_1_UART_DEFAULT_UART_RX_CTRL \
                    (SPIS_1_GET_UART_RX_CTRL_MODE(SPIS_1_UART_STOP_BITS_NUM)                    | \
                     SPIS_1_GET_UART_RX_CTRL_POLARITY(SPIS_1_UART_IRDA_POLARITY)                | \
                     SPIS_1_GET_UART_RX_CTRL_MP_MODE(SPIS_1_UART_MP_MODE_ENABLE)                | \
                     SPIS_1_GET_UART_RX_CTRL_DROP_ON_PARITY_ERR(SPIS_1_UART_DROP_ON_PARITY_ERR) | \
                     SPIS_1_GET_UART_RX_CTRL_DROP_ON_FRAME_ERR(SPIS_1_UART_DROP_ON_FRAME_ERR)   | \
                     SPIS_1_UART_DEFAULT_RX_CTRL_PARITY)

    #define SPIS_1_UART_DEFAULT_RX_CTRL \
                                (SPIS_1_GET_RX_CTRL_DATA_WIDTH(SPIS_1_UART_DATA_BITS_NUM)        | \
                                 SPIS_1_GET_RX_CTRL_MEDIAN    (SPIS_1_UART_MEDIAN_FILTER_ENABLE) | \
                                 SPIS_1_GET_UART_RX_CTRL_ENABLED(SPIS_1_UART_DIRECTION))

    #define SPIS_1_UART_DEFAULT_RX_FIFO_CTRL \
                                SPIS_1_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(SPIS_1_UART_RX_TRIGGER_LEVEL)

    #define SPIS_1_UART_DEFAULT_RX_MATCH_REG  ((0u != SPIS_1_UART_MP_MODE_ENABLE) ?          \
                                (SPIS_1_GET_RX_MATCH_ADDR(SPIS_1_UART_MP_RX_ADDRESS) | \
                                 SPIS_1_GET_RX_MATCH_MASK(SPIS_1_UART_MP_RX_ADDRESS_MASK)) : (0u))

    /* TX direction */
    #define SPIS_1_UART_DEFAULT_TX_CTRL_PARITY (SPIS_1_UART_DEFAULT_RX_CTRL_PARITY)

    #define SPIS_1_UART_DEFAULT_UART_TX_CTRL \
                                (SPIS_1_GET_UART_TX_CTRL_MODE(SPIS_1_UART_STOP_BITS_NUM)       | \
                                 SPIS_1_GET_UART_TX_CTRL_RETRY_NACK(SPIS_1_UART_RETRY_ON_NACK) | \
                                 SPIS_1_UART_DEFAULT_TX_CTRL_PARITY)

    #define SPIS_1_UART_DEFAULT_TX_CTRL \
                                (SPIS_1_GET_TX_CTRL_DATA_WIDTH(SPIS_1_UART_DATA_BITS_NUM) | \
                                 SPIS_1_GET_UART_TX_CTRL_ENABLED(SPIS_1_UART_DIRECTION))

    #define SPIS_1_UART_DEFAULT_TX_FIFO_CTRL \
                                SPIS_1_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(SPIS_1_UART_TX_TRIGGER_LEVEL)

    /* Interrupt sources */
    #define SPIS_1_UART_DEFAULT_INTR_I2C_EC_MASK  (SPIS_1_NO_INTR_SOURCES)
    #define SPIS_1_UART_DEFAULT_INTR_SPI_EC_MASK  (SPIS_1_NO_INTR_SOURCES)
    #define SPIS_1_UART_DEFAULT_INTR_SLAVE_MASK   (SPIS_1_NO_INTR_SOURCES)
    #define SPIS_1_UART_DEFAULT_INTR_MASTER_MASK  (SPIS_1_NO_INTR_SOURCES)
    #define SPIS_1_UART_DEFAULT_INTR_RX_MASK      (SPIS_1_UART_INTR_RX_MASK)
    #define SPIS_1_UART_DEFAULT_INTR_TX_MASK      (SPIS_1_UART_INTR_TX_MASK)

#endif /* (SPIS_1_SCB_MODE_UART_CONST_CFG) */

#endif /* CY_SCB_SPI_UART_SPIS_1_H */


/* [] END OF FILE */
