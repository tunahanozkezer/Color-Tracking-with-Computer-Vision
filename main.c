#include "main.h"
#include "stm32f4xx_hal.h"


UART_HandleTypeDef huart2;


void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
int sure=0, i=0, sayi=0,sayac=0,yon;
uint8_t buffrec[1];
char led_veri[1];
void ileri(sure){
	yon=1;
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15,0);
	HAL_Delay(sure);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14|GPIO_PIN_15,0);
	HAL_Delay(sure);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_14|GPIO_PIN_15,0);
	HAL_Delay(sure);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_14,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_15,0);
	HAL_Delay(sure);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_12|GPIO_PIN_15,0);
	HAL_Delay(sure);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14|GPIO_PIN_15,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13,0);
	HAL_Delay(sure);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14,0);
	HAL_Delay(sure);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15|GPIO_PIN_12,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_14,0);
	HAL_Delay(sure);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15,0);
	HAL_Delay(sure);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14|GPIO_PIN_15,0);
	HAL_Delay(sure);
//	sayi++;
	
}

void geri(sure){
	yon=2;
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14,0);
	HAL_Delay(sure);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15|GPIO_PIN_14,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_12,0);
	HAL_Delay(sure);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_12|GPIO_PIN_15,0);
	HAL_Delay(sure);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14|GPIO_PIN_13,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_15,0);
	HAL_Delay(sure);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_14|GPIO_PIN_15,0);
	HAL_Delay(sure);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_12,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14|GPIO_PIN_15,0);
	HAL_Delay(sure);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15,0);
	HAL_Delay(sure);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_15,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14|GPIO_PIN_13,0);
	HAL_Delay(sure);
	//sayi++;
}
void ileri_adimli(adim){
	for(sayac=0; sayac<adim; sayac++){
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15,0);
	HAL_Delay(sure);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14|GPIO_PIN_15,0);
	HAL_Delay(sure);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_14|GPIO_PIN_15,0);
	HAL_Delay(sure);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_14,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_15,0);
	HAL_Delay(sure);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_12|GPIO_PIN_15,0);
	HAL_Delay(sure);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14|GPIO_PIN_15,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13,0);
	HAL_Delay(sure);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14,0);
	HAL_Delay(sure);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15|GPIO_PIN_12,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_14,0);
	HAL_Delay(sure);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15,0);
	HAL_Delay(sure);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14|GPIO_PIN_15,0);
	HAL_Delay(sure);
		}
	sayi=0;
}
void geri_adimli(adim){
	for(sayac=0; sayac<adim; sayac++){
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14,0);
	HAL_Delay(sure);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15|GPIO_PIN_14,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_12,0);
	HAL_Delay(sure);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_12|GPIO_PIN_15,0);
	HAL_Delay(sure);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14|GPIO_PIN_13,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_15,0);
	HAL_Delay(sure);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_14|GPIO_PIN_15,0);
	HAL_Delay(sure);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_12,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14|GPIO_PIN_15,0);
	HAL_Delay(sure);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15,0);
	HAL_Delay(sure);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_15,1);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14|GPIO_PIN_13,0);
	HAL_Delay(sure);
		}
	sayi=0;
}



int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART2_UART_Init();

	__HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);
  while (1)
  {
		//Step Motor Bölümü
		if(buffrec[0] == '1'){ileri(2);}
		if(buffrec[0] == '3'){ geri(2);}
		if(buffrec[0] == '2'){HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15,0);sayi=0;}
		if(buffrec[0] == '0'){
		//if(yon==1){geri_adimli(sayi);}
		//if(yon==2){ileri_adimli(sayi);}
		HAL_GPIO_WritePin(GPIOE,led1_Pin|led2_Pin|led3_Pin|led4_Pin|led5_Pin|led6_Pin|led7_Pin|led8_Pin|led9_Pin,0);
		}
		
		//Led Bölümü
		if(buffrec[0] == 'a'){ //X=1 Y=1
			HAL_GPIO_WritePin(GPIOE,led1_Pin,1); 
		  HAL_GPIO_WritePin(GPIOE,led2_Pin|led3_Pin|led4_Pin|led5_Pin|led6_Pin|led7_Pin|led8_Pin|led9_Pin,0);}
		if(buffrec[0] == 'b'){ //X=2 Y=1
			HAL_GPIO_WritePin(GPIOE,led2_Pin,1); 
		  HAL_GPIO_WritePin(GPIOE,led1_Pin|led3_Pin|led4_Pin|led5_Pin|led6_Pin|led7_Pin|led8_Pin|led9_Pin,0);}
		if(buffrec[0] == 'c'){ //X=3 Y=1
			HAL_GPIO_WritePin(GPIOE,led3_Pin,1); 
		  HAL_GPIO_WritePin(GPIOE,led2_Pin|led1_Pin|led4_Pin|led5_Pin|led6_Pin|led7_Pin|led8_Pin|led9_Pin,0);}
		if(buffrec[0] == 'd'){ //X=1 Y=2
			HAL_GPIO_WritePin(GPIOE,led4_Pin,1); 
		  HAL_GPIO_WritePin(GPIOE,led2_Pin|led3_Pin|led1_Pin|led5_Pin|led6_Pin|led7_Pin|led8_Pin|led9_Pin,0);}
		if(buffrec[0] == 'e'){ //X=2 Y=2
			HAL_GPIO_WritePin(GPIOE,led5_Pin,1); 
		  HAL_GPIO_WritePin(GPIOE,led2_Pin|led3_Pin|led4_Pin|led1_Pin|led6_Pin|led7_Pin|led8_Pin|led9_Pin,0);}
		if(buffrec[0] == 'f'){ //X=3 Y=2
			HAL_GPIO_WritePin(GPIOE,led6_Pin,1); 
		  HAL_GPIO_WritePin(GPIOE,led2_Pin|led3_Pin|led4_Pin|led5_Pin|led1_Pin|led7_Pin|led8_Pin|led9_Pin,0);}
		if(buffrec[0] == 'g'){ //X=1 Y=3
			HAL_GPIO_WritePin(GPIOE,led7_Pin,1); 
		  HAL_GPIO_WritePin(GPIOE,led2_Pin|led3_Pin|led4_Pin|led5_Pin|led6_Pin|led1_Pin|led8_Pin|led9_Pin,0);}
		if(buffrec[0] == 'h'){ //X=2 Y=3
			HAL_GPIO_WritePin(GPIOE,led8_Pin,1); 
		  HAL_GPIO_WritePin(GPIOE,led2_Pin|led3_Pin|led4_Pin|led5_Pin|led6_Pin|led7_Pin|led1_Pin|led9_Pin,0);}
		if(buffrec[0] == 'i'){ //X=3 Y=3
			HAL_GPIO_WritePin(GPIOE,led9_Pin,1); 
		  HAL_GPIO_WritePin(GPIOE,led2_Pin|led3_Pin|led4_Pin|led5_Pin|led6_Pin|led7_Pin|led8_Pin|led1_Pin,0);}
  }
}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* USART2 init function */
static void MX_USART2_UART_Init(void)
{

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, CS_I2C_SPI_Pin|led1_Pin|led2_Pin|led3_Pin 
                          |led4_Pin|led5_Pin|led6_Pin|led7_Pin 
                          |led8_Pin|led9_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(OTG_FS_PowerSwitchOn_GPIO_Port, OTG_FS_PowerSwitchOn_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, Step1_Pin|Step2_Pin|Step3_Pin|Step4_Pin 
                          |Audio_RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : CS_I2C_SPI_Pin led1_Pin led2_Pin led3_Pin 
                           led4_Pin led5_Pin led6_Pin led7_Pin 
                           led8_Pin led9_Pin */
  GPIO_InitStruct.Pin = CS_I2C_SPI_Pin|led1_Pin|led2_Pin|led3_Pin 
                          |led4_Pin|led5_Pin|led6_Pin|led7_Pin 
                          |led8_Pin|led9_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : OTG_FS_PowerSwitchOn_Pin */
  GPIO_InitStruct.Pin = OTG_FS_PowerSwitchOn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(OTG_FS_PowerSwitchOn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PDM_OUT_Pin */
  GPIO_InitStruct.Pin = PDM_OUT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(PDM_OUT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : I2S3_WS_Pin */
  GPIO_InitStruct.Pin = I2S3_WS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
  HAL_GPIO_Init(I2S3_WS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : SPI1_SCK_Pin SPI1_MISO_Pin SPI1_MOSI_Pin */
  GPIO_InitStruct.Pin = SPI1_SCK_Pin|SPI1_MISO_Pin|SPI1_MOSI_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : BOOT1_Pin */
  GPIO_InitStruct.Pin = BOOT1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(BOOT1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : CLK_IN_Pin */
  GPIO_InitStruct.Pin = CLK_IN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(CLK_IN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : Step1_Pin Step2_Pin Step3_Pin Step4_Pin 
                           Audio_RST_Pin */
  GPIO_InitStruct.Pin = Step1_Pin|Step2_Pin|Step3_Pin|Step4_Pin 
                          |Audio_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : I2S3_MCK_Pin I2S3_SCK_Pin I2S3_SD_Pin */
  GPIO_InitStruct.Pin = I2S3_MCK_Pin|I2S3_SCK_Pin|I2S3_SD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : VBUS_FS_Pin */
  GPIO_InitStruct.Pin = VBUS_FS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(VBUS_FS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : OTG_FS_ID_Pin OTG_FS_DM_Pin OTG_FS_DP_Pin */
  GPIO_InitStruct.Pin = OTG_FS_ID_Pin|OTG_FS_DM_Pin|OTG_FS_DP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : OTG_FS_OverCurrent_Pin */
  GPIO_InitStruct.Pin = OTG_FS_OverCurrent_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(OTG_FS_OverCurrent_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : Audio_SCL_Pin Audio_SDA_Pin */
  GPIO_InitStruct.Pin = Audio_SCL_Pin|Audio_SDA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : MEMS_INT2_Pin */
  GPIO_InitStruct.Pin = MEMS_INT2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(MEMS_INT2_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
