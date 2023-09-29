/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  13/7/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* SWC				:  GPIO							 		    */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "REGISTERS.h"
#include "ERROR_STATE.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "MGPIO_config.h"
#include "MGPIO_priv.h"

ErrorState_t MGPIO_enSetPinDirection(PORT_t copy_u8port, PIN_t copy_u8pin, MODE_t copy_u8Mode)
{
	ErrorState_t local_state = SUCCESS;
	switch(copy_u8port)
	{
	case PORTA:
		if (copy_u8pin < GPIO_CRL_MAX)
		{
			GPIOA->GPIO_CRL &= ~(GPIO_MASK << (copy_u8pin * GPIO_OFFSET)) ;
			GPIOA->GPIO_CRL |= copy_u8Mode << (copy_u8pin * GPIO_OFFSET) ;
		}
		else if(copy_u8pin < GPIO_CRH_MAX)
		{
			copy_u8pin -= GPIO_CRL_MAX  ;
			GPIOA->GPIO_CRH &= ~(GPIO_MASK << (copy_u8pin * GPIO_OFFSET));
			GPIOA->GPIO_CRH |= (copy_u8Mode << (copy_u8pin * GPIO_OFFSET));
		}
		else
		{
			local_state = OUT_OF_RANG_ERR;
		}
		break;

	case PORTB:
		if (copy_u8pin < GPIO_CRL_MAX)
		{
			GPIOB->GPIO_CRL &= ~(GPIO_MASK) << (copy_u8pin * GPIO_OFFSET) ;
			GPIOB->GPIO_CRL |= (copy_u8Mode << (copy_u8pin * GPIO_OFFSET)) ;
		}
		else if(copy_u8pin < GPIO_CRH_MAX)
		{
			copy_u8pin -= GPIO_CRL_MAX ;
			GPIOB->GPIO_CRH &= ~(GPIO_MASK) << (copy_u8pin * GPIO_OFFSET) ;
			GPIOB->GPIO_CRH |= (copy_u8Mode << (copy_u8pin * GPIO_OFFSET)) ;
		}
		else
		{
			local_state = OUT_OF_RANG_ERR;
		}
		break;

	case PORTC:
		if (copy_u8pin < GPIO_CRL_MAX)
		{
			GPIOC->GPIO_CRL &= ~(GPIO_MASK << (copy_u8pin * GPIO_OFFSET)) ;
			GPIOC->GPIO_CRL |= (copy_u8Mode << (copy_u8pin * GPIO_OFFSET)) ;
		}
		else if(copy_u8pin < GPIO_CRH_MAX)
		{
			copy_u8pin -= GPIO_CRL_MAX ;
			GPIOC->GPIO_CRH &= ~(GPIO_MASK) << (copy_u8pin * GPIO_OFFSET) ;
			GPIOC->GPIO_CRH |= (copy_u8Mode << (copy_u8pin * GPIO_OFFSET)) ;
		}
		else
		{
			local_state = OUT_OF_RANG_ERR;
		}
		break;

	default:
		local_state = OUT_OF_RANG_ERR;
		break;
	}
	return local_state;
}

ErrorState_t MGPIO_enSetPinValue(PORT_t copy_u8port, PIN_t copy_u8pin, VALUE_t copy_u8Value)
{
	ErrorState_t local_state = SUCCESS;
	switch(copy_u8port)
	{
	case PORTA:
		if (copy_u8Value == HIGH)
		{
			SET_BIT(GPIOA->GPIO_ODR, copy_u8pin);
		}
		else if(copy_u8Value == LOW)
		{
			CLR_BIT(GPIOA->GPIO_ODR, copy_u8pin);
		}
		else
		{
			local_state = OUT_OF_RANG_ERR;
		}
		break;

	case PORTB:
		if (copy_u8Value == HIGH)
		{
			SET_BIT(GPIOB->GPIO_ODR, copy_u8pin);
		}
		else if(copy_u8Value == LOW)
		{
			CLR_BIT(GPIOB->GPIO_ODR, copy_u8pin);
		}
		else
		{
			local_state = OUT_OF_RANG_ERR;

		}
		break;

	case PORTC:
		if (copy_u8Value == HIGH)
		{
			SET_BIT(GPIOC->GPIO_ODR, copy_u8pin);
		}
		else if(copy_u8Value == LOW)
		{
			CLR_BIT(GPIOC->GPIO_ODR, copy_u8pin);
		}
		else
		{
			local_state = OUT_OF_RANG_ERR;
		}
		break;

	default:
		local_state = OUT_OF_RANG_ERR;
		break;
	}
	return local_state;
}

ErrorState_t MGPIO_enTogglePin(PORT_t copy_u8port, PIN_t copy_u8pin)
{
	ErrorState_t local_state = SUCCESS;
	switch(copy_u8port)
	{
	case PORTA:
		TOG_BIT(GPIOA->GPIO_ODR, copy_u8pin);
		break;

	case PORTB:
		TOG_BIT(GPIOB->GPIO_ODR, copy_u8pin);
		break;

	case PORTC:
		TOG_BIT(GPIOC->GPIO_ODR, copy_u8pin);
		break;
	default:
		local_state =  OUT_OF_RANG_ERR;
		break;
	}
	return local_state;
}


ErrorState_t MGPIO_enGetPinValue(PORT_t copy_u8port, PIN_t copy_u8pin, u8 *pinValue)
{
	ErrorState_t local_state = SUCCESS;
	switch(copy_u8port)
	{
	case PORTA:
		*pinValue = GET_BIT(GPIOA->GPIO_IDR, copy_u8pin);
		break;

	case PORTB:
		*pinValue = GET_BIT(GPIOB->GPIO_IDR, copy_u8pin);
		break;

	case PORTC:
		*pinValue = GET_BIT(GPIOC->GPIO_IDR, copy_u8pin);
		break;
	default:
		local_state =  OUT_OF_RANG_ERR;
		break;
	}

	return local_state;
}

ErrorState_t MGPIO_enSetPortDirection(GPIO_ID_t copy_u8CRID,PORT_t copy_u8port,  MODE_t copy_u8Mode)
{
	ErrorState_t local_state = SUCCESS;
	switch(copy_u8port)
	{
	case PORTA:
		if(copy_u8CRID == GPIO_CRL_ID)
		{
			GPIOA->GPIO_CRL = copy_u8Mode * PORT_OFFSET ;
		}
		else if(copy_u8CRID == GPIO_CRH_ID)
		{
			GPIOA->GPIO_CRH = copy_u8Mode * PORT_OFFSET ;
		}
		else
		{
			local_state = OUT_OF_RANG_ERR;
		}
		break;


	case PORTB:
		if(copy_u8CRID == GPIO_CRL_ID)
		{
			GPIOB->GPIO_CRL = copy_u8Mode * PORT_OFFSET ;
		}
		else if(copy_u8CRID == GPIO_CRH_ID)
		{
			GPIOB->GPIO_CRH = copy_u8Mode * PORT_OFFSET ;
		}
		else
		{
			local_state = OUT_OF_RANG_ERR;
		}
		break;

	case PORTC:
		if(copy_u8CRID == GPIO_CRL_ID)
		{
			GPIOC->GPIO_CRL = copy_u8Mode * PORT_OFFSET ;
		}
		else if(copy_u8CRID == GPIO_CRH_ID)
		{
			GPIOC->GPIO_CRH = copy_u8Mode * PORT_OFFSET ;
		}
		else
		{
			local_state = OUT_OF_RANG_ERR;
		}
		break;

	default:
		local_state = OUT_OF_RANG_ERR;
	}

	return local_state;
}

ErrorState_t MGPIO_enSetPortValue(GPIO_ID_t copy_u8CRID, PORT_t copy_u8port, VALUE_t copy_u8Value)
{
	ErrorState_t local_state = SUCCESS;

	switch(copy_u8port)
	{
	case PORTA:
		if ((copy_u8Value == HIGH) && (copy_u8CRID == GPIO_CRL_ID))
		{
			GPIOA->GPIO_ODR |= PORT_LVALUE;
		}
		else if ((copy_u8Value == HIGH) && (copy_u8CRID == GPIO_CRH_ID))
		{
			GPIOA->GPIO_ODR |= PORT_HVALUE;
		}
		else if ((copy_u8Value == LOW) && (copy_u8CRID == GPIO_CRL_ID))
		{
			GPIOA->GPIO_ODR &= ~(PORT_LVALUE);
			GPIOA->GPIO_ODR |= PORT_RESET;
		}
		else if ((copy_u8Value == LOW) && (copy_u8CRID == GPIO_CRH_ID))
		{
			GPIOA->GPIO_ODR &= ~(PORT_HVALUE);
			GPIOA->GPIO_ODR |= PORT_RESET;
		}
		else
		{
			local_state = OUT_OF_RANG_ERR;
		}
		break;

	case PORTB:
		if ((copy_u8Value == HIGH) && (copy_u8CRID == GPIO_CRL_ID))
		{
			GPIOB->GPIO_ODR |= PORT_LVALUE;
		}
		else if ((copy_u8Value == HIGH) && (copy_u8CRID == GPIO_CRH_ID))
		{
			GPIOB->GPIO_ODR |= PORT_HVALUE;
		}
		else if ((copy_u8Value == LOW) && (copy_u8CRID == GPIO_CRL_ID))
		{
			GPIOB->GPIO_ODR &= ~(PORT_LVALUE);
			GPIOB->GPIO_ODR |= PORT_RESET;
		}
		else if ((copy_u8Value == LOW) && (copy_u8CRID == GPIO_CRH_ID))
		{
			GPIOB->GPIO_ODR &= ~(PORT_HVALUE);
			GPIOB->GPIO_ODR |= PORT_RESET;
		}
		else
		{
			local_state = OUT_OF_RANG_ERR;
		}
		break;

	case PORTC:
		if ((copy_u8Value == HIGH) && (copy_u8CRID == GPIO_CRL_ID))
		{
			GPIOC->GPIO_ODR |= PORT_LVALUE;
		}
		else if ((copy_u8Value == HIGH) && (copy_u8CRID == GPIO_CRH_ID))
		{
			GPIOC->GPIO_ODR |= PORT_HVALUE;
		}
		else if ((copy_u8Value == LOW) && (copy_u8CRID == GPIO_CRL_ID))
		{
			GPIOC->GPIO_ODR &= ~(PORT_LVALUE);
			GPIOC->GPIO_ODR |= PORT_RESET;
		}
		else if ((copy_u8Value == LOW) && (copy_u8CRID == GPIO_CRH_ID))
		{
			GPIOC->GPIO_ODR &= ~(PORT_HVALUE);
			GPIOC->GPIO_ODR |= PORT_RESET;
		}
		else
		{
			local_state = OUT_OF_RANG_ERR;
		}
		break;

	default:
		local_state = OUT_OF_RANG_ERR;
		break;

	}
	return local_state;
}

ErrorState_t MGPIO_enSetResetPin(PORT_t copy_u8port,PIN_t copy_u8pin, PinMode_t copy_u8Mode)
{
	ErrorState_t local_state = SUCCESS;
	switch(copy_u8port)
	{
	case PORTA:
		if (copy_u8Mode == GPIO_PIN_SET)
		{
			GPIOA->GPIO_BSRR = (1<<copy_u8pin);
		}
		else if(copy_u8Mode == GPIO_PIN_RESET)
		{
			GPIOA->GPIO_BRR = (1<<copy_u8pin);
		}
		else
		{
			local_state = OUT_OF_RANG_ERR;
		}
		break;

	case PORTB:
		if (copy_u8Mode == GPIO_PIN_SET)
		{
			GPIOB->GPIO_BSRR = (1<<copy_u8pin);
		}
		else if(copy_u8Mode == GPIO_PIN_RESET)
		{
			GPIOB->GPIO_BRR = (1<<copy_u8pin);
		}
		else
		{
			local_state = OUT_OF_RANG_ERR;
		}
		break;

	case PORTC:
		if (copy_u8Mode == GPIO_PIN_SET)
		{
			GPIOC->GPIO_BSRR = (1<<copy_u8pin);
		}
		else if(copy_u8Mode == GPIO_PIN_RESET)
		{
			GPIOC->GPIO_BRR = (1<<copy_u8pin);
		}
		else
		{
			local_state = OUT_OF_RANG_ERR;
		}
		break;

	default:
		local_state = OUT_OF_RANG_ERR;
		break;
	}

	return local_state;
}

ErrorState_t MGPIO_enLockPin(PORT_t copy_u8port, PIN_t copy_u8pin)
{
	ErrorState_t local_state = SUCCESS;
	u8 pinState ;

	switch (copy_u8port)
	{
	case PORTA:
		SET_BIT(GPIOA->GPIO_LCKR,copy_u8pin);

		SET_BIT(GPIOA->GPIO_LCKR,LCKK);
		CLR_BIT(GPIOA->GPIO_LCKR,LCKK);
		SET_BIT(GPIOA->GPIO_LCKR,LCKK);

		pinState = GET_BIT(GPIOA->GPIO_LCKR,LCKK);
		if (pinState == 0)
		{
			pinState = GET_BIT(GPIOA->GPIO_LCKR,LCKK);
			if (pinState == 1)
			{
				local_state = SUCCESS;
			}
			else
			{
				local_state = FAILARE;
			}
		}
		else
		{
			local_state = FAILARE;
		}
		break;

	case PORTB:
		SET_BIT(GPIOB->GPIO_LCKR,copy_u8pin);

		SET_BIT(GPIOB->GPIO_LCKR,LCKK);
		CLR_BIT(GPIOB->GPIO_LCKR,LCKK);
		SET_BIT(GPIOB->GPIO_LCKR,LCKK);

		pinState = GET_BIT(GPIOB->GPIO_LCKR,LCKK);
		if (pinState == 0)
		{
			pinState = GET_BIT(GPIOB->GPIO_LCKR,LCKK);
			if (pinState == 1)
			{
				local_state = SUCCESS;
			}
			else
			{
				local_state = FAILARE;
			}
		}
		else
		{
			local_state = FAILARE;
		}
		break;

	case PORTC:
		SET_BIT(GPIOC->GPIO_LCKR,copy_u8pin);

		SET_BIT(GPIOC->GPIO_LCKR,LCKK);
		CLR_BIT(GPIOC->GPIO_LCKR,LCKK);
		SET_BIT(GPIOC->GPIO_LCKR,LCKK);

		pinState = GET_BIT(GPIOC->GPIO_LCKR,LCKK);
		if (pinState == 0)
		{
			pinState = GET_BIT(GPIOC->GPIO_LCKR,LCKK);
			if (pinState == 1)
			{
				local_state = SUCCESS;
			}
			else
			{
				local_state = FAILARE;
			}
		}
		else
		{
			local_state = FAILARE;
		}
		break;

	default:
		local_state = OUT_OF_RANG_ERR;
		break;
	}

 	return local_state;
}
