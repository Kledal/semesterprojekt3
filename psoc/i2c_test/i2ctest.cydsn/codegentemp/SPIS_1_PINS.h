/*******************************************************************************
* File Name: SPIS_1_PINS.h
* Version 1.10
*
* Description:
*  This file provides constants and parameter values for the pin components
*  buried into SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PINS_SPIS_1_H)
#define CY_SCB_PINS_SPIS_1_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* Unconfigured pins */
#define SPIS_1_REMOVE_MOSI_SCL_RX_WAKE_PIN    (1u)
#define SPIS_1_REMOVE_MOSI_SCL_RX_PIN         (1u)
#define SPIS_1_REMOVE_MISO_SDA_TX_PIN         (1u)
#define SPIS_1_REMOVE_SCLK_PIN                (1u)
#define SPIS_1_REMOVE_SS0_PIN                 (1u)
#define SPIS_1_REMOVE_SS1_PIN                 (1u)
#define SPIS_1_REMOVE_SS2_PIN                 (1u)
#define SPIS_1_REMOVE_SS3_PIN                 (1u)

/* Mode defined pins */
#define SPIS_1_REMOVE_I2C_PINS                (1u)
#define SPIS_1_REMOVE_SPI_MASTER_PINS         (1u)
#define SPIS_1_REMOVE_SPI_SLAVE_PINS          (0u)
#define SPIS_1_REMOVE_SPI_MASTER_SS0_PIN      (1u)
#define SPIS_1_REMOVE_SPI_MASTER_SS1_PIN      (1u)
#define SPIS_1_REMOVE_SPI_MASTER_SS2_PIN      (1u)
#define SPIS_1_REMOVE_SPI_MASTER_SS3_PIN      (1u)
#define SPIS_1_REMOVE_UART_TX_PIN             (1u)
#define SPIS_1_REMOVE_UART_RX_TX_PIN          (1u)
#define SPIS_1_REMOVE_UART_RX_PIN             (1u)
#define SPIS_1_REMOVE_UART_RX_WAKE_PIN        (1u)

/* Unconfigured pins */
#define SPIS_1_MOSI_SCL_RX_WAKE_PIN   (0u == SPIS_1_REMOVE_MOSI_SCL_RX_WAKE_PIN)
#define SPIS_1_MOSI_SCL_RX_PIN        (0u == SPIS_1_REMOVE_MOSI_SCL_RX_PIN)
#define SPIS_1_MISO_SDA_TX_PIN        (0u == SPIS_1_REMOVE_MISO_SDA_TX_PIN)
#define SPIS_1_SCLK_PIN               (0u == SPIS_1_REMOVE_SCLK_PIN)
#define SPIS_1_SS0_PIN                (0u == SPIS_1_REMOVE_SS0_PIN)
#define SPIS_1_SS1_PIN                (0u == SPIS_1_REMOVE_SS1_PIN)
#define SPIS_1_SS2_PIN                (0u == SPIS_1_REMOVE_SS2_PIN)
#define SPIS_1_SS3_PIN                (0u == SPIS_1_REMOVE_SS3_PIN)

/* Mode defined pins */
#define SPIS_1_I2C_PINS               (0u == SPIS_1_REMOVE_I2C_PINS)
#define SPIS_1_SPI_MASTER_PINS        (0u == SPIS_1_REMOVE_SPI_MASTER_PINS) 
#define SPIS_1_SPI_SLAVE_PINS         (0u == SPIS_1_REMOVE_SPI_SLAVE_PINS)
#define SPIS_1_SPI_MASTER_SS0_PIN     (0u == SPIS_1_REMOVE_SPI_MASTER_SS0_PIN)
#define SPIS_1_SPI_MASTER_SS1_PIN     (0u == SPIS_1_REMOVE_SPI_MASTER_SS1_PIN)
#define SPIS_1_SPI_MASTER_SS2_PIN     (0u == SPIS_1_REMOVE_SPI_MASTER_SS2_PIN)
#define SPIS_1_SPI_MASTER_SS3_PIN     (0u == SPIS_1_REMOVE_SPI_MASTER_SS3_PIN)
#define SPIS_1_UART_TX_PIN            (0u == SPIS_1_REMOVE_UART_TX_PIN)
#define SPIS_1_UART_RX_TX_PIN         (0u == SPIS_1_REMOVE_UART_RX_TX_PIN)
#define SPIS_1_UART_RX_PIN            (0u == SPIS_1_REMOVE_UART_RX_PIN)
#define SPIS_1_UART_RX_WAKE_PIN       (0u == SPIS_1_REMOVE_UART_RX_WAKE_PIN)


/***************************************
*             Includes
****************************************/

#if(SPIS_1_MOSI_SCL_RX_WAKE_PIN)
    #include "SPIS_1_spi_mosi_i2c_scl_uart_rx_wake.h"
#endif /* (SPIS_1_MOSI_SCL_RX_WAKE_PIN) */

#if(SPIS_1_MOSI_SCL_RX_PIN)
    #include "SPIS_1_spi_mosi_i2c_scl_uart_rx.h"
#endif /* (SPIS_1_MOSI_SCL_RX_PIN) */

#if(SPIS_1_MISO_SDA_TX_PIN)
    #include "SPIS_1_spi_miso_i2c_sda_uart_tx.h"
#endif /* (SPIS_1_MISO_SDA_TX_PIN_PIN) */

#if(SPIS_1_SCLK_PIN)
    #include "SPIS_1_spi_sclk.h"
#endif /* (SPIS_1_SCLK_PIN) */

#if(SPIS_1_SS0_PIN)
    #include "SPIS_1_spi_ss0.h"
#endif /* (SPIS_1_SS1_PIN) */

#if(SPIS_1_SS1_PIN)
    #include "SPIS_1_spi_ss1.h"
#endif /* (SPIS_1_SS1_PIN) */

#if(SPIS_1_SS2_PIN)
    #include "SPIS_1_spi_ss2.h"
#endif /* (SPIS_1_SS2_PIN) */

#if(SPIS_1_SS3_PIN)
    #include "SPIS_1_spi_ss3.h"
#endif /* (SPIS_1_SS3_PIN) */

#if(SPIS_1_I2C_PINS)
    #include "SPIS_1_scl.h"
    #include "SPIS_1_sda.h"
#endif /* (SPIS_1_I2C_PINS) */
    
#if(SPIS_1_SPI_MASTER_PINS)
    #include "SPIS_1_sclk_m.h"
    #include "SPIS_1_mosi_m.h"
    #include "SPIS_1_miso_m.h"
#endif /* (SPIS_1_SPI_MASTER_PINS) */

#if(SPIS_1_SPI_SLAVE_PINS)
    #include "SPIS_1_sclk_s.h"
    #include "SPIS_1_mosi_s.h"
    #include "SPIS_1_miso_s.h"
    #include "SPIS_1_ss_s.h"
#endif /* (SPIS_1_SPI_SLAVE_PINS) */

#if(SPIS_1_SPI_MASTER_SS0_PIN)
    #include "SPIS_1_ss0_m.h"
#endif /* (SPIS_1_SPI_MASTER_SS0_PIN) */

#if(SPIS_1_SPI_MASTER_SS1_PIN)
    #include "SPIS_1_ss1_m.h"
#endif /* (SPIS_1_SPI_MASTER_SS1_PIN) */

#if(SPIS_1_SPI_MASTER_SS2_PIN)
    #include "SPIS_1_ss2_m.h"
#endif /* (SPIS_1_SPI_MASTER_SS2_PIN) */

#if(SPIS_1_SPI_MASTER_SS3_PIN)
    #include "SPIS_1_ss3_m.h"
#endif /* (SPIS_1_SPI_MASTER_SS3_PIN) */

#if(SPIS_1_UART_TX_PIN)
    #include "SPIS_1_tx.h"
#endif /* (SPIS_1_UART_TX_PIN) */

#if(SPIS_1_UART_RX_TX_PIN)
    #include "SPIS_1_rx_tx.h"
#endif /* (SPIS_1_UART_RX_TX_PIN) */

#if(SPIS_1_UART_RX_PIN)
    #include "SPIS_1_rx.h"
#endif /* (SPIS_1_UART_RX_PIN) */

#if(SPIS_1_UART_RX_WAKE_PIN)
    #include "SPIS_1_rx_wake.h"
#endif /* (SPIS_1_UART_RX_WAKE_PIN) */


/***************************************
*              Registers
***************************************/

#if(SPIS_1_MOSI_SCL_RX_WAKE_PIN)
    #define SPIS_1_MOSI_SCL_RX_WAKE_HSIOM_REG  \
                                                (*(reg32 *) SPIS_1_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM)
    #define SPIS_1_MOSI_SCL_RX_WAKE_HSIOM_PTR  \
                                                ( (reg32 *) SPIS_1_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM)
    #define SPIS_1_MOSI_SCL_RX_WAKE_HSIOM_MASK \
                                                (SPIS_1_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM_MASK)
    #define SPIS_1_MOSI_SCL_RX_WAKE_HSIOM_POS  \
                                                (SPIS_1_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM_SHIFT)

    #define SPIS_1_MOSI_SCL_RX_WAKE_INTCFG_REG    (*(reg32 *) \
                                                              SPIS_1_spi_mosi_i2c_scl_uart_rx_wake__0__INTCFG)
    #define SPIS_1_MOSI_SCL_RX_WAKE_INTCFG_PTR    ( (reg32 *) \
                                                              SPIS_1_spi_mosi_i2c_scl_uart_rx_wake__0__INTCFG)

    #define SPIS_1_INTCFG_TYPE_MASK                  (0x03u)
    #define SPIS_1_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS  (SPIS_1_spi_mosi_i2c_scl_uart_rx_wake__SHIFT)
    #define SPIS_1_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK ((uint32)                                           \
                                                                    ((uint32) SPIS_1_INTCFG_TYPE_MASK << \
                                                                    SPIS_1_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS))
#endif /* (SPIS_1_MOSI_SCL_RX_WAKE_PIN) */

#if(SPIS_1_MOSI_SCL_RX_PIN)
    #define SPIS_1_MOSI_SCL_RX_HSIOM_REG      (*(reg32 *) SPIS_1_spi_mosi_i2c_scl_uart_rx__0__HSIOM)
    #define SPIS_1_MOSI_SCL_RX_HSIOM_PTR      ( (reg32 *) SPIS_1_spi_mosi_i2c_scl_uart_rx__0__HSIOM)
    #define SPIS_1_MOSI_SCL_RX_HSIOM_MASK     (SPIS_1_spi_mosi_i2c_scl_uart_rx__0__HSIOM_MASK)
    #define SPIS_1_MOSI_SCL_RX_HSIOM_POS      (SPIS_1_spi_mosi_i2c_scl_uart_rx__0__HSIOM_SHIFT)
#endif /* (SPIS_1_MOSI_SCL_RX_PIN) */

#if(SPIS_1_MISO_SDA_TX_PIN)
    #define SPIS_1_MISO_SDA_TX_HSIOM_REG      (*(reg32 *) SPIS_1_spi_miso_i2c_sda_uart_tx__0__HSIOM)
    #define SPIS_1_MISO_SDA_TX_HSIOM_PTR      ( (reg32 *) SPIS_1_spi_miso_i2c_sda_uart_tx__0__HSIOM)
    #define SPIS_1_MISO_SDA_TX_HSIOM_MASK     (SPIS_1_spi_miso_i2c_sda_uart_tx__0__HSIOM_MASK)
    #define SPIS_1_MISO_SDA_TX_HSIOM_POS      (SPIS_1_spi_miso_i2c_sda_uart_tx__0__HSIOM_SHIFT)
#endif /* (SPIS_1_MISO_SDA_TX_PIN_PIN) */

#if(SPIS_1_SCLK_PIN)
    #define SPIS_1_SCLK_HSIOM_REG     (*(reg32 *) SPIS_1_spi_sclk__0__HSIOM)
    #define SPIS_1_SCLK_HSIOM_PTR     ( (reg32 *) SPIS_1_spi_sclk__0__HSIOM)
    #define SPIS_1_SCLK_HSIOM_MASK    (SPIS_1_spi_sclk__0__HSIOM_MASK)
    #define SPIS_1_SCLK_HSIOM_POS     (SPIS_1_spi_sclk__0__HSIOM_SHIFT)
#endif /* (SPIS_1_SCLK_PIN) */

#if(SPIS_1_SS0_PIN)
    #define SPIS_1_SS0_HSIOM_REG      (*(reg32 *) SPIS_1_spi_ss0__0__HSIOM)
    #define SPIS_1_SS0_HSIOM_PTR      ( (reg32 *) SPIS_1_spi_ss0__0__HSIOM)
    #define SPIS_1_SS0_HSIOM_MASK     (SPIS_1_spi_ss0__0__HSIOM_MASK)
    #define SPIS_1_SS0_HSIOM_POS      (SPIS_1_spi_ss0__0__HSIOM_SHIFT)
#endif /* (SPIS_1_SS1_PIN) */

#if(SPIS_1_SS1_PIN)
    #define SPIS_1_SS1_HSIOM_REG      (*(reg32 *) SPIS_1_spi_ss1__0__HSIOM)
    #define SPIS_1_SS1_HSIOM_PTR      ( (reg32 *) SPIS_1_spi_ss1__0__HSIOM)
    #define SPIS_1_SS1_HSIOM_MASK     (SPIS_1_spi_ss1__0__HSIOM_MASK)
    #define SPIS_1_SS1_HSIOM_POS      (SPIS_1_spi_ss1__0__HSIOM_SHIFT)
#endif /* (SPIS_1_SS1_PIN) */

#if(SPIS_1_SS2_PIN)
    #define SPIS_1_SS2_HSIOM_REG     (*(reg32 *) SPIS_1_spi_ss2__0__HSIOM)
    #define SPIS_1_SS2_HSIOM_PTR     ( (reg32 *) SPIS_1_spi_ss2__0__HSIOM)
    #define SPIS_1_SS2_HSIOM_MASK    (SPIS_1_spi_ss2__0__HSIOM_MASK)
    #define SPIS_1_SS2_HSIOM_POS     (SPIS_1_spi_ss2__0__HSIOM_SHIFT)
#endif /* (SPIS_1_SS2_PIN) */

#if(SPIS_1_SS3_PIN)
    #define SPIS_1_SS3_HSIOM_REG     (*(reg32 *) SPIS_1_spi_ss3__0__HSIOM)
    #define SPIS_1_SS3_HSIOM_PTR     ( (reg32 *) SPIS_1_spi_ss3__0__HSIOM)
    #define SPIS_1_SS3_HSIOM_MASK    (SPIS_1_spi_ss3__0__HSIOM_MASK)
    #define SPIS_1_SS3_HSIOM_POS     (SPIS_1_spi_ss3__0__HSIOM_SHIFT)
#endif /* (SPIS_1_SS3_PIN) */

#if(SPIS_1_I2C_PINS)
    #define SPIS_1_SCL_HSIOM_REG     (*(reg32 *) SPIS_1_scl__0__HSIOM)
    #define SPIS_1_SCL_HSIOM_PTR     ( (reg32 *) SPIS_1_scl__0__HSIOM)
    #define SPIS_1_SCL_HSIOM_MASK    (SPIS_1_scl__0__HSIOM_MASK)
    #define SPIS_1_SCL_HSIOM_POS     (SPIS_1_scl__0__HSIOM_SHIFT)

    #define SPIS_1_SDA_HSIOM_REG     (*(reg32 *) SPIS_1_sda__0__HSIOM)
    #define SPIS_1_SDA_HSIOM_PTR     ( (reg32 *) SPIS_1_sda__0__HSIOM)
    #define SPIS_1_SDA_HSIOM_MASK    (SPIS_1_sda__0__HSIOM_MASK)
    #define SPIS_1_SDA_HSIOM_POS     (SPIS_1_sda__0__HSIOM_SHIFT)
#endif /* (SPIS_1_I2C_PINS) */


/***************************************
*        Registers Constants
***************************************/

/* Pins constanst */
#define SPIS_1_HSIOM_DEF_SEL      (0x00u)
#define SPIS_1_HSIOM_GPIO_SEL     (0x00u)
#define SPIS_1_HSIOM_UART_SEL     (0x09u)
#define SPIS_1_HSIOM_I2C_SEL      (0x0Eu)
#define SPIS_1_HSIOM_SPI_SEL      (0x0Fu)

#define SPIS_1_SCB_PINS_NUMBER            (7u)
#define SPIS_1_MOSI_SCL_RX_PIN_INDEX      (0u) /* RX pins without interrupt */
#define SPIS_1_MOSI_SCL_RX_WAKE_PIN_INDEX (0u) /* RX pin with interrupt     */
#define SPIS_1_MISO_SDA_TX_PIN_INDEX      (1u)
#define SPIS_1_SCLK_PIN_INDEX             (2u)
#define SPIS_1_SS0_PIN_INDEX              (3u)
#define SPIS_1_SS1_PIN_INDEX              (4u)
#define SPIS_1_SS2_PIN_INDEX              (5u)
#define SPIS_1_SS3_PIN_INDEX              (6u)

#define SPIS_1_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin DM defines */
#define SPIS_1_PIN_DM_ALG_HIZ  (0u)
#define SPIS_1_PIN_DM_DIG_HIZ  (1u)
#define SPIS_1_PIN_DM_OD_LO    (4u)
#define SPIS_1_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

#define SPIS_1_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        /* Sets new bits-mask */                 \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

#define SPIS_1_SET_HSIOM_SEL(reg, mask, pos, sel) SPIS_1_SET_REGISTER_BITS(reg, mask, pos, sel)
#define SPIS_1_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        SPIS_1_SET_REGISTER_BITS(reg, mask, pos, intType)


/* SPIS_1_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  SPIS_1_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* Unconfigured SCB: scl singnal */
#if(SPIS_1_MOSI_SCL_RX_WAKE_PIN)
    #define SPIS_1_SET_I2C_SCL_DR(val) \
                            SPIS_1_spi_mosi_i2c_scl_uart_rx_wake_Write(val)

    #define SPIS_1_SET_I2C_SCL_HSIOM_SEL(sel) \
                    SPIS_1_SET_HSIOM_SEL(SPIS_1_MOSI_SCL_RX_WAKE_HSIOM_REG,  \
                                                   SPIS_1_MOSI_SCL_RX_WAKE_HSIOM_MASK, \
                                                   SPIS_1_MOSI_SCL_RX_WAKE_HSIOM_POS,  \
                                                   (sel))

#elif(SPIS_1_MOSI_SCL_RX_PIN)
    #define SPIS_1_SET_I2C_SCL_DR(val) \
                            SPIS_1_spi_mosi_i2c_scl_uart_rx_Write(val)


    #define SPIS_1_SET_I2C_SCL_HSIOM_SEL(sel) \
                            SPIS_1_SET_HSIOM_SEL(SPIS_1_MOSI_SCL_RX_HSIOM_REG,  \
                                                           SPIS_1_MOSI_SCL_RX_HSIOM_MASK, \
                                                           SPIS_1_MOSI_SCL_RX_HSIOM_POS,  \
                                                           (sel))
#else
    #if(!SPIS_1_I2C_PINS)
        #define SPIS_1_SET_I2C_SCL_DR(val) \
                                                 do{ ; }while(0)
        #define SPIS_1_SET_I2C_SCL_HSIOM_SEL(sel) \
                                                        do{ ; }while(0)

    #endif /* (!SPIS_1_I2C_PINS) */
#endif /* (SPIS_1_MOSI_SCL_RX_PIN) */

/* SCB I2C: scl singal */
#if(SPIS_1_I2C_PINS)
    #define SPIS_1_SET_I2C_SCL_DR(val) SPIS_1_scl_Write(val)

    #define SPIS_1_SET_I2C_SCL_HSIOM_SEL(sel) \
                          SPIS_1_SET_HSIOM_SEL(SPIS_1_SCL_HSIOM_REG,  \
                                                         SPIS_1_SCL_HSIOM_MASK, \
                                                         SPIS_1_SCL_HSIOM_POS,  \
                                                         (sel))

#endif /* (SPIS_1_I2C_PINS) */


#endif /* (CY_SCB_PINS_SPIS_1_H) */


/* [] END OF FILE */
