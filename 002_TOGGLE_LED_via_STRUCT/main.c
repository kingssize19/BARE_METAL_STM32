#include <stdint.h>


#define PERIPH_BASE				(0x40000000UL)
#define AHB1PERIPH_OFFSET		(0x00020000UL)
#define AHB1PERIPH_BASE			(PERIPH_BASE + AHB1PERIPH_OFFSET)

#define GPIOA_OFFSET			(0x0000UL)
#define GPIOA_BASE				(AHB1PERIPH_BASE + GPIOA_OFFSET)

#define RCC_OFFSET				(0x3800UL)
#define RCC_BASE				(AHB1PERIPH_BASE + RCC_OFFSET)




#define GPIOAEN					(1U << 0) // 0000 0000 0000 0000 0000 0000 0000 0001

#define PIN5					(1U << 5)
#define LED_PIN					(PIN5)

#define __IO						volatile


void Delay(int time);


typedef struct {

	__IO uint32_t CR; 			        /*!< RCC clock control register, 									                  Address offset : 0x00	  */
	__IO uint32_t PLLCFGR; 		      /*!< RCC PLL configuration register, 								                Address offset : 0x04 	*/
	__IO uint32_t CFGR;			        /*!< RCC clock configuration register, 								              Address offset : 0x08 	*/
	__IO uint32_t CIR;			        /*!< RCC clock interrupt register, 									                 Address offset : 0x0C 	*/
	__IO uint32_t AHB1RSTR; 	      /*!< RCC AHB1 peripheral reset register, 							               Address offset : 0x10	*/
	__IO uint32_t AHB2RSTR;		      /*!< RCC AHB2 peripheral reset register, 							               Address offset : 0x14	*/
	__IO uint32_t AHB3RSTR;		      /*!< RCC AHB3 peripheral reset register, 							               Address offset : 0x18	*/
	uint32_t RESERVED0;			        /*!< Reserved, 0x1C 																		                                    */
	__IO uint32_t APB1RSTR;		      /*!< RCC APB1 peripheral reset register, 							              Address offset : 0x20 	*/
	__IO uint32_t APB2RSTR;		      /*!< RCC APB2 peripheral reset register, 							              Address offset : 0x24 	*/
	uint32_t RESERVED1[2];		      /*!< Reserved, 0x28-0x2C 																	                                  */
	__IO uint32_t AHB1ENR;  	      /*!< RCC AHB1 peripheral clock register, 							              Address offset : 0x30 	*/
	__IO uint32_t AHB2ENR;		      /*!< RCC AHB2 peripheral clock register, 							              Address offset : 0x34 	*/
	__IO uint32_t AHB3ENR;		      /*!< RCC AHB3 peripheral clock register, 							              Address offset : 0x38 	*/
	uint32_t RESERVED2;			        /*!< Reserved, 0x3C 																		                                    */
	__IO uint32_t APB1ENR;		      /*!< RCC APB1 peripheral clock enable register, 					          Address offset : 0x40 	*/
	__IO uint32_t APB2ENR;		      /*!< RCC APB2 peripheral clock enable register, 					          Address offset : 0x44 	*/
	uint32_t RESERVED3[2];		      /*!< Reserved, 0x48-0x4C 																	                                  */
	__IO uint32_t AHB1LPENR; 	      /*!< RCC AHB1 peripheral clock enable in low power mode register, 	Address offset : 0x50 	*/
	__IO uint32_t AHB2LPENR; 	      /*!< RCC AHB2 peripheral clock enable in low power mode register, 	Address offset : 0x54 	*/
	__IO uint32_t AHB3LPENR; 	      /*!< RCC AHB3 peripheral clock enable in low power mode register, 	Address offset : 0x58 	*/
	uint32_t RESERVED4;			        /*!< Reserved, 0x5C																			                                    */
	__IO uint32_t APB1LPENR; 	      /*!< RCC APB1 peripheral clock enable in low power mode register, 	Address offset : 0x60 	*/
	__IO uint32_t APB2LPENR; 	      /*!< RCC APB2 peripheral clock enable in low power mode register, 	Address offset : 0x64 	*/
	uint32_t RESERVED5[2];		      /*!< Reserved, 0x68-0x6C 																	                                  */
	__IO uint32_t BDCR;			        /*!< RCC Backup domain control register, 							                Address offset : 0x70	*/
	__IO uint32_t CSR;			        /*!< RCC clock control & status register, 							              Address offset : 0x74	*/
	uint32_t RESERVED6[2];		      /*!< Reserved, 0x78-0x7C 																	                                  */
	__IO uint32_t SSCGR;		        /*!< RCC spread spectrum clock generation register, 				          Address offset : 0x80	*/
	__IO uint32_t PLLI2SCFGR;
	__IO uint32_t PLLSAICFGR;
	__IO uint32_t DCKCFGR;
	__IO uint32_t CKGATENR;
	__IO uint32_t DCKCFGR2;

}RCC_TypeDef;

/*
typedef struct {
	uint32_t DUMMY[12];	// !< AHB1ENR registerından önce toplamda 12*4 = 48 byte'lık offset var ve bunları kullanmıyoruz. Bu şekilde Dummy register tanımlayabiliriz.
	__IO uint32_t AHB1ENR;
}RCC_Typedef;
*/
typedef struct {

	__IO uint32_t MODER;		/*!< GPIO port mode register,				Address offset : 0x00		*/
	__IO uint32_t OTYPER;		/*!< GPIO port output type register,		Address offset : 0x04		*/
	__IO uint32_t OSPEEDR;		/*!< GPIO port output speed register, 		Address offset : 0x08		*/
	__IO uint32_t PUPDR;		/*!< GPIO port pull-up/pull-down register,	Address offset : 0x0C		*/
	__IO uint32_t IDR;			/*!< GPIO port input data register,			Address offset : 0x10		*/
	__IO uint32_t ODR;			/*!< GPIO port output data register,		Address offset : 0x14		*/
	__IO uint32_t BSRR;			/*!< GPIO port bit set/reset register,		Address offset : 0x18		*/
	__IO uint32_t LCKR;			/*!< GPIO port configuration lock register, Address offset : 0x1C		*/
	__IO uint32_t AFR[2];		/*!< GPIO alternate function registers, 	Address offset : 0x20-0x24	*/

}GPIO_TypeDef;


#define RCC		((RCC_TypeDef *)RCC_BASE)
#define GPIOA	((GPIO_TypeDef *)GPIOA_BASE)




int main(void)
{
	/* 1. Enable clock access to GPIOA */
	RCC->AHB1ENR |= GPIOAEN;

	/* 2. Set PA5 as output mode */
	GPIOA->MODER |= (1U << 10);		// Set bit 10 to 1
	GPIOA->MODER &= ~(1U << 11);	// Set bit 11 to 0

	while (1) {

		GPIOA->ODR ^= (1U << 5);
		Delay(250000);

	}
}

void Delay(int time)
{
	for (int i = 1; i < time; ++i)
				; // null statement for delay

}






