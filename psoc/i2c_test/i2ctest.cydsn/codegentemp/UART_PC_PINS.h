/*******************************************************************************
* File Name: UART_PC_PINS.h
* Version 1.20
*
* Description:
*  This file provides constants and parameter values for the pin components
*  buried into SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PINS_UART_PC_H)
#define CY_SCB_PINS_UART_PC_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* Unconfigured pins */
#define UART_PC_REMOVE_MOSI_SCL_RX_WAKE_PIN    (1u)
#define UART_PC_REMOVE_MOSI_SCL_RX_PIN         (1u)
#define UART_PC_REMOVE_MISO_SDA_TX_PIN         (1u)
#define UART_PC_REMOVE_SCLK_PIN                (1u)
#define UART_PC_REMOVE_SS0_PIN                 (1u)
#define UART_PC_REMOVE_SS1_PIN                 (1u)
#define UART_PC_REMOVE_SS2_PIN                 (1u)
#define UART_PC_REMOVE_SS3_PIN                 (1u)

/* Mode defined pins */
#define UART_PC_REMOVE_I2C_PINS                (1u)
#define UART_PC_REMOVE_SPI_MASTER_PINS         (1u)
#define UART_PC_REMOVE_SPI_SLAVE_PINS          (1u)
#define UART_PC_REMOVE_SPI_MASTER_SS0_PIN      (1u)
#define UART_PC_REMOVE_SPI_MASTER_SS1_PIN      (1u)
#define UART_PC_REMOVE_SPI_MASTER_SS2_PIN      (1u)
#define UART_PC_REMOVE_SPI_MASTER_SS3_PIN      (1u)
#define UART_PC_REMOVE_UART_TX_PIN             (0u)
#define UART_PC_REMOVE_UART_RX_TX_PIN          (1u)
#define UART_PC_REMOVE_UART_RX_PIN             (0u)
#define UART_PC_REMOVE_UART_RX_WAKE_PIN        (1u)

/* Unconfigured pins */
#define UART_PC_MOSI_SCL_RX_WAKE_PIN   (0u == UART_PC_REMOVE_MOSI_SCL_RX_WAKE_PIN)
#define UART_PC_MOSI_SCL_RX_PIN        (0u == UART_PC_REMOVE_MOSI_SCL_RX_PIN)
#define UART_PC_MISO_SDA_TX_PIN        (0u == UART_PC_REMOVE_MISO_SDA_TX_PIN)
#define UART_PC_SCLK_PIN               (0u == UART_PC_REMOVE_SCLK_PIN)
#define UART_PC_SS0_PIN                (0u == UART_PC_REMOVE_SS0_PIN)
#define UART_PC_SS1_PIN                (0u == UART_PC_REMOVE_SS1_PIN)
#define UART_PC_SS2_PIN                (0u == UART_PC_REMOVE_SS2_PIN)
#define UART_PC_SS3_PIN                (0u == UART_PC_REMOVE_SS3_PIN)

/* Mode defined pins */
#define UART_PC_I2C_PINS               (0u == UART_PC_REMOVE_I2C_PINS)
#define UART_PC_SPI_MASTER_PINS        (0u == UART_PC_REMOVE_SPI_MASTER_PINS)
#define UART_PC_SPI_SLAVE_PINS         (0u == UART_PC_REMOVE_SPI_SLAVE_PINS)
#define UART_PC_SPI_MASTER_SS0_PIN     (0u == UART_PC_REMOVE_SPI_MASTER_SS0_PIN)
#define UART_PC_SPI_MASTER_SS1_PIN     (0u == UART_PC_REMOVE_SPI_MASTER_SS1_PIN)
#define UART_PC_SPI_MASTER_SS2_PIN     (0u == UART_PC_REMOVE_SPI_MASTER_SS2_PIN)
#define UART_PC_SPI_MASTER_SS3_PIN     (0u == UART_PC_REMOVE_SPI_MASTER_SS3_PIN)
#define UART_PC_UART_TX_PIN            (0u == UART_PC_REMOVE_UART_TX_PIN)
#define UART_PC_UART_RX_TX_PIN         (0u == UART_PC_REMOVE_UART_RX_TX_PIN)
#define UART_PC_UART_RX_PIN            (0u == UART_PC_REMOVE_UART_RX_PIN)
#define UART_PC_UART_RX_WAKE_PIN       (0u == UART_PC_REMOVE_UART_RX_WAKE_PIN)


/***************************************
*             Includes
****************************************/

#if(UART_PC_MOSI_SCL_RX_WAKE_PIN)
    #include "UART_PC_spi_mosi_i2c_scl_uart_rx_wake.h"
#endif /* (UART_PC_MOSI_SCL_RX_WAKE_PIN) */

#if(UART_PC_MOSI_SCL_RX_PIN)
    #include "UART_PC_spi_mosi_i2c_scl_uart_rx.h"
#endif /* (UART_PC_MOSI_SCL_RX_PIN) */

#if(UART_PC_MISO_SDA_TX_PIN)
    #include "UART_PC_spi_miso_i2c_sda_uart_tx.h"
#endif /* (UART_PC_MISO_SDA_TX_PIN_PIN) */

#if(UART_PC_SCLK_PIN)
    #include "UART_PC_spi_sclk.h"
#endif /* (UART_PC_SCLK_PIN) */

#if(UART_PC_SS0_PIN)
    #include "UART_PC_spi_ss0.h"
#endif /* (UART_PC_SS1_PIN) */

#if(UART_PC_SS1_PIN)
    #include "UART_PC_spi_ss1.h"
#endif /* (UART_PC_SS1_PIN) */

#if(UART_PC_SS2_PIN)
    #include "UART_PC_spi_ss2.h"
#endif /* (UART_PC_SS2_PIN) */

#if(UART_PC_SS3_PIN)
    #include "UART_PC_spi_ss3.h"
#endif /* (UART_PC_SS3_PIN) */

#if(UART_PC_I2C_PINS)
    #include "UART_PC_scl.h"
    #include "UART_PC_sda.h"
#endif /* (UART_PC_I2C_PINS) */

#if(UART_PC_SPI_MASTER_PINS)
    #include "UART_PC_sclk_m.h"
    #include "UART_PC_mosi_m.h"
    #include "UART_PC_miso_m.h"
#endif /* (UART_PC_SPI_MASTER_PINS) */

#if(UART_PC_SPI_SLAVE_PINS)
    #include "UART_PC_sclk_s.h"
    #include "UART_PC_mosi_s.h"
    #include "UART_PC_miso_s.h"
    #include "UART_PC_ss_s.h"
#endif /* (UART_PC_SPI_SLAVE_PINS) */

#if(UART_PC_SPI_MASTER_SS0_PIN)
    #include "UART_PC_ss0_m.h"
#endif /* (UART_PC_SPI_MASTER_SS0_PIN) */

#if(UART_PC_SPI_MASTER_SS1_PIN)
    #include "UART_PC_ss1_m.h"
#endif /* (UART_PC_SPI_MASTER_SS1_PIN) */

#if(UART_PC_SPI_MASTER_SS2_PIN)
    #include "UART_PC_ss2_m.h"
#endif /* (UART_PC_SPI_MASTER_SS2_PIN) */

#if(UART_PC_SPI_MASTER_SS3_PIN)
    #include "UART_PC_ss3_m.h"
#endif /* (UART_PC_SPI_MASTER_SS3_PIN) */

#if(UART_PC_UART_TX_PIN)
    #include "UART_PC_tx.h"
#endif /* (UART_PC_UART_TX_PIN) */

#if(UART_PC_UART_RX_TX_PIN)
    #include "UART_PC_rx_tx.h"
#endif /* (UART_PC_UART_RX_TX_PIN) */

#if(UART_PC_UART_RX_PIN)
    #include "UART_PC_rx.h"
#endif /* (UART_PC_UART_RX_PIN) */

#if(UART_PC_UART_RX_WAKE_PIN)
    #include "UART_PC_rx_wake.h"
#endif /* (UART_PC_UART_RX_WAKE_PIN) */


/***************************************
*              Registers
***************************************/

#if(UART_PC_MOSI_SCL_RX_WAKE_PIN)
    #define UART_PC_MOSI_SCL_RX_WAKE_HSIOM_REG  \
                                                (*(reg32 *) UART_PC_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM)
    #define UART_PC_MOSI_SCL_RX_WAKE_HSIOM_PTR  \
                                                ( (reg32 *) UART_PC_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM)
    #define UART_PC_MOSI_SCL_RX_WAKE_HSIOM_MASK \
                                                (UART_PC_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM_MASK)
    #define UART_PC_MOSI_SCL_RX_WAKE_HSIOM_POS  \
                                                (UART_PC_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM_SHIFT)

    #define UART_PC_MOSI_SCL_RX_WAKE_INTCFG_REG    (*(reg32 *) \
                                                              UART_PC_spi_mosi_i2c_scl_uart_rx_wake__0__INTCFG)
    #define UART_PC_MOSI_SCL_RX_WAKE_INTCFG_PTR    ( (reg32 *) \
                                                              UART_PC_spi_mosi_i2c_scl_uart_rx_wake__0__INTCFG)

    #define UART_PC_INTCFG_TYPE_MASK                  (0x03u)
    #define UART_PC_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS  (UART_PC_spi_mosi_i2c_scl_uart_rx_wake__SHIFT)
    #define UART_PC_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK ((uint32)                                           \
                                                                    ((uint32) UART_PC_INTCFG_TYPE_MASK << \
                                                                    UART_PC_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS))
#endif /* (UART_PC_MOSI_SCL_RX_WAKE_PIN) */

#if(UART_PC_MOSI_SCL_RX_PIN)
    #define UART_PC_MOSI_SCL_RX_HSIOM_REG      (*(reg32 *) UART_PC_spi_mosi_i2c_scl_uart_rx__0__HSIOM)
    #define UART_PC_MOSI_SCL_RX_HSIOM_PTR      ( (reg32 *) UART_PC_spi_mosi_i2c_scl_uart_rx__0__HSIOM)
    #define UART_PC_MOSI_SCL_RX_HSIOM_MASK     (UART_PC_spi_mosi_i2c_scl_uart_rx__0__HSIOM_MASK)
    #define UART_PC_MOSI_SCL_RX_HSIOM_POS      (UART_PC_spi_mosi_i2c_scl_uart_rx__0__HSIOM_SHIFT)
#endif /* (UART_PC_MOSI_SCL_RX_PIN) */

#if(UART_PC_MISO_SDA_TX_PIN)
    #define UART_PC_MISO_SDA_TX_HSIOM_REG      (*(reg32 *) UART_PC_spi_miso_i2c_sda_uart_tx__0__HSIOM)
    #define UART_PC_MISO_SDA_TX_HSIOM_PTR      ( (reg32 *) UART_PC_spi_miso_i2c_sda_uart_tx__0__HSIOM)
    #define UART_PC_MISO_SDA_TX_HSIOM_MASK     (UART_PC_spi_miso_i2c_sda_uart_tx__0__HSIOM_MASK)
    #define UART_PC_MISO_SDA_TX_HSIOM_POS      (UART_PC_spi_miso_i2c_sda_uart_tx__0__HSIOM_SHIFT)
#endif /* (UART_PC_MISO_SDA_TX_PIN_PIN) */

#if(UART_PC_SCLK_PIN)
    #define UART_PC_SCLK_HSIOM_REG     (*(reg32 *) UART_PC_spi_sclk__0__HSIOM)
    #define UART_PC_SCLK_HSIOM_PTR     ( (reg32 *) UART_PC_spi_sclk__0__HSIOM)
    #define UART_PC_SCLK_HSIOM_MASK    (UART_PC_spi_sclk__0__HSIOM_MASK)
    #define UART_PC_SCLK_HSIOM_POS     (UART_PC_spi_sclk__0__HSIOM_SHIFT)
#endif /* (UART_PC_SCLK_PIN) */

#if(UART_PC_SS0_PIN)
    #define UART_PC_SS0_HSIOM_REG      (*(reg32 *) UART_PC_spi_ss0__0__HSIOM)
    #define UART_PC_SS0_HSIOM_PTR      ( (reg32 *) UART_PC_spi_ss0__0__HSIOM)
    #define UART_PC_SS0_HSIOM_MASK     (UART_PC_spi_ss0__0__HSIOM_MASK)
    #define UART_PC_SS0_HSIOM_POS      (UART_PC_spi_ss0__0__HSIOM_SHIFT)
#endif /* (UART_PC_SS1_PIN) */

#if(UART_PC_SS1_PIN)
    #define UART_PC_SS1_HSIOM_REG      (*(reg32 *) UART_PC_spi_ss1__0__HSIOM)
    #define UART_PC_SS1_HSIOM_PTR      ( (reg32 *) UART_PC_spi_ss1__0__HSIOM)
    #define UART_PC_SS1_HSIOM_MASK     (UART_PC_spi_ss1__0__HSIOM_MASK)
    #define UART_PC_SS1_HSIOM_POS      (UART_PC_spi_ss1__0__HSIOM_SHIFT)
#endif /* (UART_PC_SS1_PIN) */

#if(UART_PC_SS2_PIN)
    #define UART_PC_SS2_HSIOM_REG     (*(reg32 *) UART_PC_spi_ss2__0__HSIOM)
    #define UART_PC_SS2_HSIOM_PTR     ( (reg32 *) UART_PC_spi_ss2__0__HSIOM)
    #define UART_PC_SS2_HSIOM_MASK    (UART_PC_spi_ss2__0__HSIOM_MASK)
    #define UART_PC_SS2_HSIOM_POS     (UART_PC_spi_ss2__0__HSIOM_SHIFT)
#endif /* (UART_PC_SS2_PIN) */

#if(UART_PC_SS3_PIN)
    #define UART_PC_SS3_HSIOM_REG     (*(reg32 *) UART_PC_spi_ss3__0__HSIOM)
    #define UART_PC_SS3_HSIOM_PTR     ( (reg32 *) UART_PC_spi_ss3__0__HSIOM)
    #define UART_PC_SS3_HSIOM_MASK    (UART_PC_spi_ss3__0__HSIOM_MASK)
    #define UART_PC_SS3_HSIOM_POS     (UART_PC_spi_ss3__0__HSIOM_SHIFT)
#endif /* (UART_PC_SS3_PIN) */

#if(UART_PC_I2C_PINS)
    #define UART_PC_SCL_HSIOM_REG     (*(reg32 *) UART_PC_scl__0__HSIOM)
    #define UART_PC_SCL_HSIOM_PTR     ( (reg32 *) UART_PC_scl__0__HSIOM)
    #define UART_PC_SCL_HSIOM_MASK    (UART_PC_scl__0__HSIOM_MASK)
    #define UART_PC_SCL_HSIOM_POS     (UART_PC_scl__0__HSIOM_SHIFT)

    #define UART_PC_SDA_HSIOM_REG     (*(reg32 *) UART_PC_sda__0__HSIOM)
    #define UART_PC_SDA_HSIOM_PTR     ( (reg32 *) UART_PC_sda__0__HSIOM)
    #define UART_PC_SDA_HSIOM_MASK    (UART_PC_sda__0__HSIOM_MASK)
    #define UART_PC_SDA_HSIOM_POS     (UART_PC_sda__0__HSIOM_SHIFT)
#endif /* (UART_PC_I2C_PINS) */


/***************************************
*        Registers Constants
***************************************/

/* Pins constants */
#define UART_PC_HSIOM_DEF_SEL      (0x00u)
#define UART_PC_HSIOM_GPIO_SEL     (0x00u)
#define UART_PC_HSIOM_UART_SEL     (0x09u)
#define UART_PC_HSIOM_I2C_SEL      (0x0Eu)
#define UART_PC_HSIOM_SPI_SEL      (0x0Fu)

#if(!UART_PC_CY_SCBIP_V1_I2C_ONLY)
    #define UART_PC_SCB_PINS_NUMBER    (7u)
#else
    #define UART_PC_SCB_PINS_NUMBER    (2u)
#endif /* (!UART_PC_CY_SCBIP_V1_I2C_ONLY) */

#define UART_PC_MOSI_SCL_RX_PIN_INDEX      (0u) /* RX pins without interrupt */
#define UART_PC_MOSI_SCL_RX_WAKE_PIN_INDEX (0u) /* RX pin with interrupt     */
#define UART_PC_MISO_SDA_TX_PIN_INDEX      (1u)
#define UART_PC_SCLK_PIN_INDEX             (2u)
#define UART_PC_SS0_PIN_INDEX              (3u)
#define UART_PC_SS1_PIN_INDEX              (4u)
#define UART_PC_SS2_PIN_INDEX              (5u)
#define UART_PC_SS3_PIN_INDEX              (6u)

#define UART_PC_MOSI_SCL_RX_PIN_MASK      ((uint32) 0x01u << UART_PC_MOSI_SCL_RX_PIN_INDEX)
#define UART_PC_MOSI_SCL_RX_WAKE_PIN_MASK ((uint32) 0x01u << UART_PC_MOSI_SCL_RX_WAKE_PIN_INDEX)
#define UART_PC_MISO_SDA_TX_PIN_MASK      ((uint32) 0x01u << UART_PC_MISO_SDA_TX_PIN_INDEX)
#define UART_PC_SCLK_PIN_MASK             ((uint32) 0x01u << UART_PC_SCLK_PIN_INDEX)
#define UART_PC_SS0_PIN_MASK              ((uint32) 0x01u << UART_PC_SS0_PIN_INDEX)
#define UART_PC_SS1_PIN_MASK              ((uint32) 0x01u << UART_PC_SS1_PIN_INDEX)
#define UART_PC_SS2_PIN_MASK              ((uint32) 0x01u << UART_PC_SS2_PIN_INDEX)
#define UART_PC_SS3_PIN_MASK              ((uint32) 0x01u << UART_PC_SS3_PIN_INDEX)

#define UART_PC_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin DM defines */
#define UART_PC_PIN_DM_ALG_HIZ  (0u)
#define UART_PC_PIN_DM_DIG_HIZ  (1u)
#define UART_PC_PIN_DM_OD_LO    (4u)
#define UART_PC_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

/* Set bits-mask in register */
#define UART_PC_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

/* Set bit the in register */
#define UART_PC_SET_REGISTER_BIT(reg, mask, val) \
                    ((val) ? ((reg) |= (mask)) : ((reg) &= ((uint32) ~((uint32) (mask)))))

#define UART_PC_SET_HSIOM_SEL(reg, mask, pos, sel) UART_PC_SET_REGISTER_BITS(reg, mask, pos, sel)
#define UART_PC_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        UART_PC_SET_REGISTER_BITS(reg, mask, pos, intType)
#define UART_PC_SET_INP_DIS(reg, mask, val) UART_PC_SET_REGISTER_BIT(reg, mask, val)

/* UART_PC_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  UART_PC_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* SCB I2C: scl signal */
#if(UART_PC_I2C_PINS)
    #define UART_PC_SET_I2C_SCL_DR(val) UART_PC_scl_Write(val)

    #define UART_PC_SET_I2C_SCL_HSIOM_SEL(sel) \
                          UART_PC_SET_HSIOM_SEL(UART_PC_SCL_HSIOM_REG,  \
                                                         UART_PC_SCL_HSIOM_MASK, \
                                                         UART_PC_SCL_HSIOM_POS,  \
                                                         (sel))
    #define UART_PC_WAIT_SCL_SET_HIGH  (0u == UART_PC_scl_Read())

/* Unconfigured SCB: scl signal */
#elif(UART_PC_MOSI_SCL_RX_WAKE_PIN)
    #define UART_PC_SET_I2C_SCL_DR(val) \
                            UART_PC_spi_mosi_i2c_scl_uart_rx_wake_Write(val)

    #define UART_PC_SET_I2C_SCL_HSIOM_SEL(sel) \
                    UART_PC_SET_HSIOM_SEL(UART_PC_MOSI_SCL_RX_WAKE_HSIOM_REG,  \
                                                   UART_PC_MOSI_SCL_RX_WAKE_HSIOM_MASK, \
                                                   UART_PC_MOSI_SCL_RX_WAKE_HSIOM_POS,  \
                                                   (sel))

    #define UART_PC_WAIT_SCL_SET_HIGH  (0u == UART_PC_spi_mosi_i2c_scl_uart_rx_wake_Read())

#elif(UART_PC_MOSI_SCL_RX_PIN)
    #define UART_PC_SET_I2C_SCL_DR(val) \
                            UART_PC_spi_mosi_i2c_scl_uart_rx_Write(val)


    #define UART_PC_SET_I2C_SCL_HSIOM_SEL(sel) \
                            UART_PC_SET_HSIOM_SEL(UART_PC_MOSI_SCL_RX_HSIOM_REG,  \
                                                           UART_PC_MOSI_SCL_RX_HSIOM_MASK, \
                                                           UART_PC_MOSI_SCL_RX_HSIOM_POS,  \
                                                           (sel))

    #define UART_PC_WAIT_SCL_SET_HIGH  (0u == UART_PC_spi_mosi_i2c_scl_uart_rx_Read())

#else
    #define UART_PC_SET_I2C_SCL_DR(val) \
                                                    do{ ; }while(0)
    #define UART_PC_SET_I2C_SCL_HSIOM_SEL(sel) \
                                                    do{ ; }while(0)

    #define UART_PC_WAIT_SCL_SET_HIGH  (0u)
#endif /* (UART_PC_MOSI_SCL_RX_PIN) */

/* SCB I2C: sda signal */
#if(UART_PC_I2C_PINS)
    #define UART_PC_WAIT_SDA_SET_HIGH  (0u == UART_PC_sda_Read())

/* Unconfigured SCB: sda signal */
#elif(UART_PC_MISO_SDA_TX_PIN)
    #define UART_PC_WAIT_SDA_SET_HIGH  (0u == UART_PC_spi_miso_i2c_sda_uart_tx_Read())

#else
    #define UART_PC_WAIT_SDA_SET_HIGH  (0u)
#endif /* (UART_PC_MOSI_SCL_RX_PIN) */

#endif /* (CY_SCB_PINS_UART_PC_H) */


/* [] END OF FILE */
