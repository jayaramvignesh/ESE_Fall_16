/***************************************************************************
 *
 *  	Filename: nRF24L01.h
 *      Description:  This header file contains the functions for NRF24L01
 *
 *      Author: Arundhathi Swami and Vignesh Jayaram
 *      Date: November 7,2016
 *
 ****************************************************************************/

#include "MKL25Z4.h"

/* Memory Map */
#define CONFIG_NRF      0x00
#define EN_AA_NRF       0x01
#define EN_RXADDR_NRF   0x02
#define SETUP_AW_NRF    0x03
#define SETUP_RETR_NRF  0x04
#define RF_CH_NRF       0x05
#define RF_SETUP_NRF    0x06
#define STATUS_NRF      0x07
#define OBSERVE_TX_NRF  0x08
#define CD_NRF          0x09
#define RX_ADDR_P0_NRF  0x0A
#define RX_ADDR_P1_NRF  0x0B
#define RX_ADDR_P2_NRF  0x0C
#define RX_ADDR_P3_NRF  0x0D
#define RX_ADDR_P4_NRF  0x0E
#define RX_ADDR_P5_NRF  0x0F
#define TX_ADDR_NRF     0x10
#define RX_PW_P0_NRF    0x11
#define RX_PW_P1_NRF    0x12
#define RX_PW_P2_NRF    0x13
#define RX_PW_P3_NRF    0x14
#define RX_PW_P4_NRF    0x15
#define RX_PW_P5_NRF    0x16
#define FIFO_STATUS_NRF 0x17
#define DYNPD_NRF	      0x1C
#define FEATURE_NRF	    0x1D

/* Bit Mnemonics */
#define MASK_RX_DR_NRF  6
#define MASK_TX_DS_NRF  5
#define MASK_MAX_RT_NRF 4
#define EN_CRC_NRF      3
#define CRCO_NRF        2
#define PWR_UP_NRF      1
#define PRIM_RX_NRF     0
#define ENAA_P5_NRF     5
#define ENAA_P4_NRF     4
#define ENAA_P3_NRF     3
#define ENAA_P2_NRF     2
#define ENAA_P1_NRF     1
#define ENAA_P0_NRF     0
#define ERX_P5_NRF      5
#define ERX_P4_NRF      4
#define ERX_P3_NRF      3
#define ERX_P2_NRF      2
#define ERX_P1_NRF      1
#define ERX_P0_NRF      0
#define AW_NRF          0
#define ARD_NRF         4
#define ARC_NRF         0
#define PLL_LOCK_NRF    4
#define RF_DR_NRF       3
#define RF_PWR_NRF      6
#define RX_DR_NRF       6
#define TX_DS_NRF       5
#define MAX_RT_NRF      4
#define RX_P_NO_NRF     1
#define TX_FULL_NRF     0
#define PLOS_CNT_NRF    4
#define ARC_CNT_NRF     0
#define TX_REUSE_NRF    6
#define FIFO_FULL_NRF   5
#define TX_EMPTY_NRF    4
#define RX_FULL_NRF     1
#define RX_EMPTY_NRF    0
#define DPL_P5_NRF	    5
#define DPL_P4_NRF	    4
#define DPL_P3_NRF	    3
#define DPL_P2_NRF	    2
#define DPL_P1_NRF	    1
#define DPL_P0_NRF	    0
#define EN_DPL_NRF	    2
#define EN_ACK_PAY_NRF  1
#define EN_DYN_ACK _NRF 0

/* Instruction Mnemonics */
#define READ_REGISTER    0x00
#define WRITE_REGISTER    0x20
#define REGISTER_MASK 0x1F
#define ACTIVATE      0x50
#define R_RX_PL_WID   0x60
#define R_RX_PAYLOAD  0x61
#define W_TX_PAYLOAD  0xA0
#define W_ACK_PAYLOAD 0xA8
#define FLUSH_TX      0xE1
#define FLUSH_RX      0xE2
#define REUSE_TX_PL   0xE3
#define NOP           0xFF

/* Non-P omissions */
#define LNA_HCURR   0

/* P model memory Map */
#define RPD         0x09

/* P model bit Mnemonics */
#define DR_LOW_RF   5
#define DR_HIGH_RF 3
#define PWR_LOW_RF  1
#define PWR_HIGH_RF 2

/*Function Prototypes*/

void chipenable_low(void);
void chipenable_high(void);
uint8_t register_write(uint8_t reg_addr,uint8_t data);
uint8_t register_read(uint8_t reg_addr);
uint8_t register_multiplebytes_read(uint8_t reg_addr,uint8_t* read_value, uint8_t length );
uint8_t register_multiplebytes_write(uint8_t reg_addr,uint8_t* data, uint8_t length );
