/**
  ******************************************************************************
  * @file    APP/CanProtocol.h
  * @author  Samwu
  * @version V1.0.0
  * @date    24-2-2016
  * @brief   Evaluation board specific configuration file.
  ******************************************************************************
  */ 
#ifndef __CANPROTOCOL_H
#define __CANPROTOCOL_H
/* Define to prevent recursive inclusion -------------------------------------*/
#include "platform_config.h"
#include "stm32f10x.h"                         // STM32F10x Library Definitions 

#define USE_CAN_TEST
#define USE_CAN_AUTO_TEST
//#define USE_CAN_NORMAL

/* Private typedef -----------------------------------------------------------*/
/* Can receiving character relevant variables */
typedef union
{
	struct
	{
		uint8_t StdIDAddr:3;          /*!< bit:  0..2   stdid                  */
		uint8_t ExtIDAddr:5;          /*!< bit:  3..7   extid                  */
	}CanIDAddr;
	uint8_t IDAddr;
} CAN_STDEXTIDAddrTypedef;

typedef union
{
	struct
	{
		uint32_t FunCode:5;         /*!< bit:  0..4  CMD Code                  */
		uint32_t SrcAddr:3;         /*!< bit:  5..7  source address            */
		uint32_t DstAddr:3;         /*!< bit:  8..10 destination address       */
		uint32_t ExtSrcAddr:5;
		uint32_t ExtDstAddr:5;
		uint32_t RESERVED0:8;       /*!< bit: 25..31 Reserved                  */
	}CanProtocolId;
	uint32_t Id;
} CAN_EXTSTDIDTypedef;

typedef struct
{
	uint8_t SrcAddr;             /*!< source address               */
	uint8_t DstAddr;             /*!< destination address          */ 
	uint8_t CanCmd;
	uint8_t IdType;              /*!< CAN ID type                  */
	uint8_t data[8];
} CAN_MessageTypedef;

/* Can commond code */
#define CAN_CMD_READ_AD             0x01     /* Read adc value cmd code */
#define CAN_CMD_RW_EEPROM           0x02     /* Read and write cmd code */
#define CAN_CMD_CHECK_BOARD         0x03     /* check themself cmd code */
#define CAN_CMD_RW_SN_ID            0x04     /* Read SN id cmd code     */
#define CAN_CMD_CALIBRATION_TEMP    0x05     /* Calculate and set calibration temperature parameter */


/* Private function prototypes -----------------------------------------------*/
void CAN_MessageGet( CanRxMsg *pMessage );
void Can_Process( void );
void Can_cmd_parse( void );

void Can_change_return_id( CanTxMsg *pMessage, uint8_t cmd );
	
void Can_show_sn_msg( void );
void Can_return_sn_msg( void );

void Can_show_ad_msg( void );
void Can_return_ad_msg( void );

void Can_show_eeprom_msg( void );
void Can_return_eeprom_msg( void );

void Can_show_board_msg( void );
void Can_return_board_msg( void );

void Can_show_Calibration_temp_msg( void );

void Can_eeprom_auto_test( uint16_t Cnt );
void Can_test_eeprom_msg( uint8_t CanEepromTestCmd[] );
void Can_Adc_auto_test( uint16_t Cnt );

void SetCanAutoTest( uint8_t Flg );
uint8_t IsCanAutoTest( void );
void CanAutoTestOkAdd( void );
void CanAutoTestErrAdd( void );

#endif