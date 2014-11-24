/*******************************************************************************
* File Name: SPIS_1_SPI.c
* Version 1.10
*
* Description:
*  This file provides the source code to the API for the SCB Component in
*  SPI mode.
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

#if(SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG)

    /***************************************
    *  Config Structure Initialization
    ***************************************/

    const SPIS_1_SPI_INIT_STRUCT SPIS_1_configSpi =
    {
        SPIS_1_SPI_MODE,
        SPIS_1_SPI_SUB_MODE,
        SPIS_1_SPI_CLOCK_MODE,
        SPIS_1_SPI_OVS_FACTOR,
        SPIS_1_SPI_MEDIAN_FILTER_ENABLE,
        SPIS_1_SPI_LATE_MISO_SAMPLE_ENABLE,
        SPIS_1_SPI_WAKE_ENABLE,
        SPIS_1_SPI_RX_DATA_BITS_NUM,
        SPIS_1_SPI_TX_DATA_BITS_NUM,
        SPIS_1_SPI_BITS_ORDER,
        SPIS_1_SPI_TRANSFER_SEPARATION,
        0u,
        NULL,
        0u,
        NULL,
        SPIS_1_SCB_IRQ_INTERNAL,
        SPIS_1_SPI_INTR_RX_MASK,
        SPIS_1_SPI_RX_TRIGGER_LEVEL,
        SPIS_1_SPI_INTR_TX_MASK,
        SPIS_1_SPI_TX_TRIGGER_LEVEL
    };


    /*******************************************************************************
    * Function Name: SPIS_1_SpiInit
    ********************************************************************************
    *
    * Summary:
    *  Configures the SCB for SPI operation.
    *
    * Parameters:
    *  config:  Pointer to a structure that contains the following ordered list of
    *           fields. These fields match the selections available in the
    *           customizer.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SPIS_1_SpiInit(const SPIS_1_SPI_INIT_STRUCT *config)
    {
        if(NULL == config)
        {
            CYASSERT(0u != 0u); /* Halt execution due bad fucntion parameter */
        }
        else
        {
            /* Configure pins */
            SPIS_1_SetPins(SPIS_1_SCB_MODE_SPI, config->mode, SPIS_1_DUMMY_PARAM);

            /* Store internal configuration */
            SPIS_1_scbMode       = (uint8) SPIS_1_SCB_MODE_SPI;
            SPIS_1_scbEnableWake = (uint8) config->enableWake;
            SPIS_1_scbEnableIntr = (uint8) config->enableInterrupt;

            /* Set RX direction internal variables */
            SPIS_1_rxBuffer      =         config->rxBuffer;
            SPIS_1_rxDataBits    = (uint8) config->rxDataBits;
            SPIS_1_rxBufferSize  = (uint8) config->rxBufferSize;

            /* Set TX direction internal variables */
            SPIS_1_txBuffer      =         config->txBuffer;
            SPIS_1_txDataBits    = (uint8) config->txDataBits;
            SPIS_1_txBufferSize  = (uint8) config->txBufferSize;


            /* Configure SPI interface */
            SPIS_1_CTRL_REG     = SPIS_1_GET_CTRL_OVS(config->oversample)        |
                                            SPIS_1_GET_CTRL_EC_AM_MODE(config->enableWake) |
                                            SPIS_1_CTRL_SPI;

            SPIS_1_SPI_CTRL_REG = SPIS_1_GET_SPI_CTRL_CONTINUOUS    (config->transferSeperation)  |
                                            SPIS_1_GET_SPI_CTRL_SELECT_PRECEDE(config->submode &
                                                                          SPIS_1_SPI_MODE_TI_PRECEDES_MASK) |
                                            SPIS_1_GET_SPI_CTRL_SCLK_MODE     (config->sclkMode)            |
                                            SPIS_1_GET_SPI_CTRL_LATE_MISO_SAMPLE(config->enableLateSampling)|
                                            SPIS_1_GET_SPI_CTRL_SUB_MODE      (config->submode)             |
                                            SPIS_1_GET_SPI_CTRL_MASTER_MODE   (config->mode);

            /* Configure RX direction */
            SPIS_1_RX_CTRL_REG     =  SPIS_1_GET_RX_CTRL_DATA_WIDTH(config->rxDataBits)         |
                                                SPIS_1_GET_RX_CTRL_BIT_ORDER (config->bitOrder)           |
                                                SPIS_1_GET_RX_CTRL_MEDIAN    (config->enableMedianFilter) |
                                                SPIS_1_SPI_RX_CTRL;

            SPIS_1_RX_FIFO_CTRL_REG = SPIS_1_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(config->rxTriggerLevel);

            /* Configure TX direction */
            SPIS_1_TX_CTRL_REG      = SPIS_1_GET_TX_CTRL_DATA_WIDTH(config->txDataBits) |
                                                SPIS_1_GET_TX_CTRL_BIT_ORDER (config->bitOrder)   |
                                                SPIS_1_SPI_TX_CTRL;

            SPIS_1_TX_FIFO_CTRL_REG = SPIS_1_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(config->txTriggerLevel);

            /* Configure interrupt with SPI handler */
            SPIS_1_SCB_IRQ_Disable();
            SPIS_1_SCB_IRQ_SetVector(&SPIS_1_SPI_UART_ISR);
            SPIS_1_SCB_IRQ_SetPriority((uint8)SPIS_1_SCB_IRQ_INTC_PRIOR_NUMBER);

            /* Configure interrupt sources */
            SPIS_1_INTR_I2C_EC_MASK_REG = SPIS_1_NO_INTR_SOURCES;
            SPIS_1_INTR_SPI_EC_MASK_REG = SPIS_1_NO_INTR_SOURCES;
            SPIS_1_INTR_SLAVE_MASK_REG  = SPIS_1_GET_SPI_INTR_SLAVE_MASK(config->rxInterruptMask);
            SPIS_1_INTR_MASTER_MASK_REG = SPIS_1_GET_SPI_INTR_MASTER_MASK(config->txInterruptMask);
            SPIS_1_INTR_RX_MASK_REG     = SPIS_1_GET_SPI_INTR_RX_MASK(config->rxInterruptMask);
            SPIS_1_INTR_TX_MASK_REG     = SPIS_1_GET_SPI_INTR_TX_MASK(config->txInterruptMask);


            /* Clear RX buffer indexes */
            SPIS_1_rxBufferHead     = 0u;
            SPIS_1_rxBufferTail     = 0u;
            SPIS_1_rxBufferOverflow = 0u;

            /* Clrea TX buffer indexes */
            SPIS_1_txBufferHead = 0u;
            SPIS_1_txBufferTail = 0u;
        }
    }

#else

    /*******************************************************************************
    * Function Name: SPIS_1_SpiInit
    ********************************************************************************
    *
    * Summary:
    *  Configures the SCB for SPI operation.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SPIS_1_SpiInit(void)
    {
        /* Configure SPI interface */
        SPIS_1_CTRL_REG     = SPIS_1_SPI_DEFAULT_CTRL;
        SPIS_1_SPI_CTRL_REG = SPIS_1_SPI_DEFAULT_SPI_CTRL;

        /* Configure TX and RX direction */
        SPIS_1_RX_CTRL_REG      = SPIS_1_SPI_DEFAULT_RX_CTRL;
        SPIS_1_RX_FIFO_CTRL_REG = SPIS_1_SPI_DEFAULT_RX_FIFO_CTRL;

        /* Configure TX and RX direction */
        SPIS_1_TX_CTRL_REG      = SPIS_1_SPI_DEFAULT_TX_CTRL;
        SPIS_1_TX_FIFO_CTRL_REG = SPIS_1_SPI_DEFAULT_TX_FIFO_CTRL;

        /* Configure interrupt with SPI handler */
        #if(SPIS_1_SCB_IRQ_INTERNAL)
            SPIS_1_SCB_IRQ_Disable();
            SPIS_1_SCB_IRQ_SetVector(&SPIS_1_SPI_UART_ISR);
            SPIS_1_SCB_IRQ_SetPriority((uint8)SPIS_1_SCB_IRQ_INTC_PRIOR_NUMBER);
        #endif /* (SPIS_1_SCB_IRQ_INTERNAL) */
        
        /* Configure interrupt sources */
        SPIS_1_INTR_I2C_EC_MASK_REG = SPIS_1_SPI_DEFAULT_INTR_I2C_EC_MASK;
        SPIS_1_INTR_SPI_EC_MASK_REG = SPIS_1_SPI_DEFAULT_INTR_SPI_EC_MASK;
        SPIS_1_INTR_SLAVE_MASK_REG  = SPIS_1_SPI_DEFAULT_INTR_SLAVE_MASK;
        SPIS_1_INTR_MASTER_MASK_REG = SPIS_1_SPI_DEFAULT_INTR_MASTER_MASK;
        SPIS_1_INTR_RX_MASK_REG     = SPIS_1_SPI_DEFAULT_INTR_RX_MASK;
        SPIS_1_INTR_TX_MASK_REG     = SPIS_1_SPI_DEFAULT_INTR_TX_MASK;

        #if(SPIS_1_INTERNAL_RX_SW_BUFFER_CONST)
            SPIS_1_rxBufferHead     = 0u;
            SPIS_1_rxBufferTail     = 0u;
            SPIS_1_rxBufferOverflow = 0u;
        #endif /* (SPIS_1_INTERNAL_RX_SW_BUFFER_CONST) */

        #if(SPIS_1_INTERNAL_TX_SW_BUFFER_CONST)
            SPIS_1_txBufferHead = 0u;
            SPIS_1_txBufferTail = 0u;
        #endif /* (SPIS_1_INTERNAL_TX_SW_BUFFER_CONST) */
    }

#endif /* (SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG) */


/*******************************************************************************
* Function Name: SPIS_1_SetActiveSlaveSelect
********************************************************************************
*
* Summary:
*  Selects one of the four SPI slave select signals.
*  The component should be in one of the following states to change the active
*  slave select signal source correctly:
*   - the component is disabled
*   - the component has completed all transactions (TX FIFO is empty and the
*     SpiDone flag is set)
*  This function does not check that these conditions are met.
*  At initialization time the active slave select line is slave select 0.
*
* Parameters:
*  activeSelect: The four lines available to utilize Slave Select function.
*
* Return:
*  None
*
*******************************************************************************/
void SPIS_1_SpiSetActiveSlaveSelect(uint32 activeSelect)
{
    uint32 spiCtrl;

    spiCtrl = SPIS_1_SPI_CTRL_REG;

    spiCtrl &= (uint32) ~SPIS_1_SPI_CTRL_SLAVE_SELECT_MASK; /* Clear SS bits */
    spiCtrl |= (uint32)  SPIS_1_GET_SPI_CTRL_SS(activeSelect);

    SPIS_1_SPI_CTRL_REG = spiCtrl;
}


#if(SPIS_1_SPI_WAKE_ENABLE_CONST)
    /*******************************************************************************
    * Function Name: SPIS_1_SpiSaveConfig
    ********************************************************************************
    *
    * Summary:
    *  Wakeup disabled: does nothing.
    *  Wakeup  enabled: clears SCB_backup.enableState to keep component enabled
    *  while DeepSleep. The SCB_INTR_SPI_EC_WAKE_UP enabled while initialization
    *  and tracks in active mode therefore it does not require to be cleared.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    * Global variables:
    *  None
    *
    *******************************************************************************/
    void SPIS_1_SpiSaveConfig(void)
    {
        /* Clear wake-up before enable */
        SPIS_1_ClearSpiExtClkInterruptSource(SPIS_1_INTR_SPI_EC_WAKE_UP);

        /* Enable interrupt to wakeup the device */
        SPIS_1_SetSpiExtClkInterruptMode(SPIS_1_INTR_SPI_EC_WAKE_UP);
    }


    /*******************************************************************************
    * Function Name: SPIS_1_SpiRestoreConfig
    ********************************************************************************
    *
    * Summary:
    *  Does nothing.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    * Global variables:
    *  None
    *
    *******************************************************************************/
    void SPIS_1_SpiRestoreConfig(void)
    {
        /* Disable interrupt to wakeup the device */
        SPIS_1_SetSpiExtClkInterruptMode(SPIS_1_NO_INTR_SOURCES);
    }
#endif /* (SPIS_1_SPI_WAKE_ENABLE_CONST) */


/* [] END OF FILE */
