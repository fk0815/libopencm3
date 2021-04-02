/** @defgroup rcc_file RCC peripheral API
 *
 * @ingroup peripheral_apis
 *
 * @section rcc_l4_api_ex Reset and Clock Control API.
 *
 * @brief <b>libopencm3 STM32WLxx Reset and Clock Control</b>
 *
 * This library supports the Reset and Clock Control System in the STM32 series
 * of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

/**@{*/
#include <libopencm3/cm3/assert.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/flash.h>

/* Set the default clock frequencies after reset. */
uint32_t rcc_ahb_frequency = 4000000;
uint32_t rcc_apb1_frequency = 4000000;
uint32_t rcc_apb2_frequency = 4000000;

void rcc_osc_ready_int_clear(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CICR |= RCC_CICR_PLLRDYC;
		break;
	case RCC_HSE:
		RCC_CICR |= RCC_CICR_HSERDYC;
		break;
	case RCC_HSI16:
		RCC_CICR |= RCC_CICR_HSIRDYC;
		break;
	case RCC_MSI:
		RCC_CICR |= RCC_CICR_MSIRDYC;
		break;
	case RCC_LSE:
		RCC_CICR |= RCC_CICR_LSERDYC;
		break;
	case RCC_LSI:
		RCC_CICR |= RCC_CICR_LSIRDYC;
		break;
	}
}

void rcc_osc_ready_int_enable(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CIER |= RCC_CIER_PLLRDYIE;
		break;
	case RCC_HSE:
		RCC_CIER |= RCC_CIER_HSERDYIE;
		break;
	case RCC_HSI16:
		RCC_CIER |= RCC_CIER_HSIRDYIE;
		break;
	case RCC_MSI:
		RCC_CIER |= RCC_CIER_MSIRDYIE;
		break;
	case RCC_LSE:
		RCC_CIER |= RCC_CIER_LSERDYIE;
		break;
	case RCC_LSI:
		RCC_CIER |= RCC_CIER_LSIRDYIE;
		break;
	}
}

void rcc_osc_ready_int_disable(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CIER &= ~RCC_CIER_PLLRDYIE;
		break;
	case RCC_HSE:
		RCC_CIER &= ~RCC_CIER_HSERDYIE;
		break;
	case RCC_HSI16:
		RCC_CIER &= ~RCC_CIER_HSIRDYIE;
		break;
	case RCC_MSI:
		RCC_CIER &= ~RCC_CIER_MSIRDYIE;
		break;
	case RCC_LSE:
		RCC_CIER &= ~RCC_CIER_LSERDYIE;
		break;
	case RCC_LSI:
		RCC_CIER &= ~RCC_CIER_LSIRDYIE;
		break;
	}
}

int rcc_osc_ready_int_flag(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		return ((RCC_CIFR & RCC_CIFR_PLLRDYF) != 0);
		break;
	case RCC_HSE:
		return ((RCC_CIFR & RCC_CIFR_HSERDYF) != 0);
		break;
	case RCC_HSI16:
		return ((RCC_CIFR & RCC_CIFR_HSIRDYF) != 0);
		break;
	case RCC_MSI:
		return ((RCC_CIFR & RCC_CIFR_MSIRDYF) != 0);
		break;
	case RCC_LSE:
		return ((RCC_CIFR & RCC_CIFR_LSERDYF) != 0);
		break;
	case RCC_LSI:
		return ((RCC_CIFR & RCC_CIFR_LSIRDYF) != 0);
		break;
	}
	return false;

}

void rcc_css_int_clear(void)
{
	RCC_CICR |= RCC_CICR_CSSC;
}

int rcc_css_int_flag(void)
{
	return ((RCC_CIFR & RCC_CIFR_CSSF) != 0);
}

bool rcc_is_osc_ready(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		return RCC_CR & RCC_CR_PLLRDY;
	case RCC_HSE:
		return RCC_CR & RCC_CR_HSERDY;
	case RCC_HSI16:
		return RCC_CR & RCC_CR_HSIRDY;
	case RCC_MSI:
		return RCC_CR & RCC_CR_MSIRDY;
	case RCC_LSE:
		return RCC_BDCR & RCC_BDCR_LSERDY;
	case RCC_LSI:
		return RCC_CSR & RCC_CSR_LSIRDY;
	}
	return false;
}

void rcc_wait_for_osc_ready(enum rcc_osc osc)
{
	while (!rcc_is_osc_ready(osc));
}

void rcc_wait_for_sysclk_status(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK)
			!= RCC_CFGR_SWS_PLLR);
		break;
	case RCC_HSE:
		while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK)
			!= RCC_CFGR_SWS_HSE);
		break;
	case RCC_HSI16:
		while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK)
			!= RCC_CFGR_SWS_HSI16);
		break;
	case RCC_MSI:
		while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK)
			!= RCC_CFGR_SWS_MSI);
		break;
	default:
		/* Shouldn't be reached. */
		break;
	}
}

void rcc_osc_on(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CR |= RCC_CR_PLLON;
		break;
	case RCC_HSE:
		RCC_CR |= RCC_CR_HSEON;
		break;
	case RCC_HSI16:
		RCC_CR |= RCC_CR_HSION;
		break;
	case RCC_MSI:
		RCC_CR |= RCC_CR_MSION;
		break;
	case RCC_LSE:
		RCC_BDCR |= RCC_BDCR_LSEON;
		break;
	case RCC_LSI:
		RCC_CSR |= RCC_CSR_LSION;
		break;
	}
}

void rcc_osc_off(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CR &= ~RCC_CR_PLLON;
		break;
	case RCC_HSE:
		RCC_CR &= ~RCC_CR_HSEON;
		break;
	case RCC_HSI16:
		RCC_CR &= ~RCC_CR_HSION;
		break;
	case RCC_MSI:
		RCC_CR &= ~RCC_CR_MSION;
		break;
	case RCC_LSE:
		RCC_BDCR &= ~RCC_BDCR_LSEON;
		break;
	case RCC_LSI:
		RCC_CSR &= ~RCC_CSR_LSION;
		break;
	}
}

void rcc_css_enable(void)
{
	RCC_CR |= RCC_CR_CSSON;
}

void rcc_css_disable(void)
{
	RCC_CR &= ~RCC_CR_CSSON;
}

void rcc_set_sysclk_source(uint32_t clk)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_SW_MASK << RCC_CFGR_SW_SHIFT);
	RCC_CFGR = (reg32 | (clk << RCC_CFGR_SW_SHIFT));
}

void rcc_set_pll_source(uint32_t pllsrc)
{
	uint32_t reg32;

	reg32 = RCC_PLLCFGR;
	reg32 &= ~(RCC_PLLCFGR_PLLSRC_MASK << RCC_PLLCFGR_PLLSRC_SHIFT);
	RCC_PLLCFGR = (reg32 | (pllsrc << RCC_PLLCFGR_PLLSRC_SHIFT));
}

void rcc_set_ppre2(uint32_t ppre2)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_PPRE2_MASK << RCC_CFGR_PPRE2_SHIFT);
	RCC_CFGR = (reg32 | (ppre2 << RCC_CFGR_PPRE2_SHIFT));
}

void rcc_set_ppre1(uint32_t ppre1)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_PPRE1_MASK << RCC_CFGR_PPRE1_SHIFT);
	RCC_CFGR = (reg32 | (ppre1 << RCC_CFGR_PPRE1_SHIFT));
}

void rcc_set_hpre(uint32_t hpre)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_HPRE_MASK << RCC_CFGR_HPRE_SHIFT);
	RCC_CFGR = (reg32 | (hpre << RCC_CFGR_HPRE_SHIFT));
}

void rcc_set_main_pll(uint32_t source, uint32_t pllm, uint32_t plln, uint32_t pllp,
	uint32_t pllq, uint32_t pllr)
{
	uint32_t pllcfgr =
		((source & RCC_PLLCFGR_PLLSRC_MASK) << RCC_PLLCFGR_PLLSRC_SHIFT) |
		((RCC_PLLCFGR_PLLM_DIV(pllm) & RCC_PLLCFGR_PLLM_MASK) << RCC_PLLCFGR_PLLM_SHIFT) |
		((RCC_PLLCFGR_PLLN_MUL(plln) & RCC_PLLCFGR_PLLN_MASK) << RCC_PLLCFGR_PLLN_SHIFT);
	if(pllp) {
		pllcfgr |= ((RCC_PLLCFGR_PLLP_DIV(pllp) & RCC_PLLCFGR_PLLP_MASK) << RCC_PLLCFGR_PLLP_SHIFT);
		pllcfgr |= RCC_PLLCFGR_PLLPEN;
	}
	if(pllq) {
		pllcfgr |= ((RCC_PLLCFGR_PLLQ_DIV(pllq) & RCC_PLLCFGR_PLLQ_MASK) << RCC_PLLCFGR_PLLQ_SHIFT);
		pllcfgr |= RCC_PLLCFGR_PLLQEN;
	}
	if(pllr) {
		pllcfgr |= ((RCC_PLLCFGR_PLLR_DIV(pllr) & RCC_PLLCFGR_PLLR_MASK) << RCC_PLLCFGR_PLLR_SHIFT);
		pllcfgr |= RCC_PLLCFGR_PLLREN;
	}
	RCC_PLLCFGR = pllcfgr;
}

uint32_t rcc_system_clock_source(void)
{
	/* Return the clock source which is used as system clock. */
	return (RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK;
}

/**
 * Set the msi run time range.
 * Can only be called when MSI is either OFF, or when MSI is on _and_
 * ready. (RCC_CR_MSIRDY bit).  @sa rcc_set_msi_range_standby
 * @param msi_range range number @ref rcc_cr_msirange
 */
void rcc_set_msi_range(uint32_t msi_range)
{
	uint32_t reg = RCC_CR;
	reg &= ~(RCC_CR_MSIRANGE_MASK << RCC_CR_MSIRANGE_SHIFT);
	reg |= msi_range << RCC_CR_MSIRANGE_SHIFT;
	RCC_CR = reg | RCC_CR_MSIRGSEL;
}

/**
 * Set the msi range after reset/standby.
 * Until MSIRGSEl bit is set, this defines the MSI range.
 * Note that not all MSI range values are allowed here!
 * @sa rcc_set_msi_range
 * @param msi_range range number valid for post standby @ref rcc_csr_msirange
 */
void rcc_set_msi_range_standby(uint32_t msi_range)
{
	uint32_t reg = RCC_CSR;
	reg &= ~(RCC_CSR_MSIRANGE_MASK << RCC_CSR_MSIRANGE_SHIFT);
	reg |= msi_range << RCC_CSR_MSIRANGE_SHIFT;
	RCC_CSR = reg;
}

/** Enable PLL Output
 *
 *	- P (RCC_PLLCFGR_PLLPEN)
 *	- Q (RCC_PLLCFGR_PLLQEN)
 *	- R (RCC_PLLCFGR_PLLREN)
 *
 * @param pllout One or more of the definitions above
 */
void rcc_pll_output_enable(uint32_t pllout)
{
	RCC_PLLCFGR |= pllout;
}

/** Enable the RTC clock */
void rcc_enable_rtc_clock(void)
{
	RCC_BDCR |= RCC_BDCR_RTCEN;
}

/** Disable the RTC clock */
void rcc_disable_rtc_clock(void)
{
	RCC_BDCR &= ~RCC_BDCR_RTCEN;
}

/** Set the source for the RTC clock
 * @param[in] clk ::rcc_osc. RTC clock source. Only HSE/32, LSE and LSI.
 */
void rcc_set_rtc_clock_source(enum rcc_osc clk)
{
	RCC_BDCR &= ~(RCC_BDCR_RTCSEL_MASK << RCC_BDCR_RTCSEL_SHIFT);

	switch (clk) {
	case RCC_HSE:
		RCC_BDCR |= (RCC_BDCR_RTCSEL_HSEDIV32 << RCC_BDCR_RTCSEL_SHIFT);
		break;
	case RCC_LSE:
		RCC_BDCR |= (RCC_BDCR_RTCSEL_LSE << RCC_BDCR_RTCSEL_SHIFT);
		break;
	case RCC_LSI:
		RCC_BDCR |= (RCC_BDCR_RTCSEL_LSI << RCC_BDCR_RTCSEL_SHIFT);
		break;
	default:
		/* none selected */
		break;
	}
}

/* Helper to calculate the frequency of a UART/I2C based on the apb and clksel value. */
static uint32_t rcc_uart_i2c_clksel_freq_hz(uint32_t pclk, uint8_t shift) {
	uint8_t clksel = (RCC_CCIPR >> shift) & RCC_CCIPR_USARTxSEL_MASK;
	uint8_t hpre = (RCC_CFGR >> RCC_CFGR_HPRE_SHIFT) & RCC_CFGR_HPRE_MASK;
	switch (clksel) {
		case RCC_CCIPR_USARTxSEL_PCLK:
			return pclk;
		case RCC_CCIPR_USARTxSEL_SYS:
			return rcc_ahb_frequency * rcc_get_div_from_hpre(hpre);
		case RCC_CCIPR_USARTxSEL_HSI16:
			return 16000000U;
	}
	cm3_assert_not_reached();
}

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the USART at base specified.
 * @param usart  Base address of USART to get clock frequency for.
 */
uint32_t rcc_get_usart_clk_freq(uint32_t usart)
{
	/* Handle values with selectable clocks. */
	if (usart == LPUART1_BASE) {
		return rcc_uart_i2c_clksel_freq_hz(rcc_apb2_frequency, RCC_CCIPR_LPUART1SEL_SHIFT);
	} else if (usart == USART1_BASE) {
		return rcc_uart_i2c_clksel_freq_hz(rcc_apb1_frequency, RCC_CCIPR_USART1SEL_SHIFT);
	} else {
		/* USART2 */
		return rcc_uart_i2c_clksel_freq_hz(rcc_apb1_frequency, RCC_CCIPR_USART2SEL_SHIFT);
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the Timer at base specified.
 * @param timer  Base address of TIM to get clock frequency for.
 */
uint32_t rcc_get_timer_clk_freq(uint32_t timer)
{
	/* Handle APB1 timers, and apply multiplier if necessary. */
	if (timer == TIM2_BASE) {
		uint8_t ppre1 = (RCC_CFGR >> RCC_CFGR_PPRE1_SHIFT) & RCC_CFGR_PPRE1_MASK;
		return (ppre1 == RCC_CFGR_PPRE1_NODIV) ? rcc_apb1_frequency
			: 2 * rcc_apb1_frequency;
	} else {
		uint8_t ppre2 = (RCC_CFGR >> RCC_CFGR_PPRE2_SHIFT) & RCC_CFGR_PPRE2_MASK;
		return (ppre2 == RCC_CFGR_PPRE2_NODIV) ? rcc_apb2_frequency
			: 2 * rcc_apb2_frequency;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the I2C device at base specified.
 * @param i2c  Base address of I2C to get clock frequency for.
 */
uint32_t rcc_get_i2c_clk_freq(uint32_t i2c)
{
	if (i2c == I2C1_BASE) {
		return rcc_uart_i2c_clksel_freq_hz(rcc_apb1_frequency, RCC_CCIPR_I2C1SEL_SHIFT);
	} else if (i2c == I2C2_BASE) {
		return rcc_uart_i2c_clksel_freq_hz(rcc_apb1_frequency, RCC_CCIPR_I2C2SEL_SHIFT);
	} else {  /* I2C3 */
		return rcc_uart_i2c_clksel_freq_hz(rcc_apb1_frequency, RCC_CCIPR_I2C3SEL_SHIFT);
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the SPI device at base specified.
 * @param spi  Base address of SPI device to get clock frequency for (e.g. SPI1_BASE).
 */
uint32_t rcc_get_spi_clk_freq(uint32_t spi) {
	if (spi == SPI1_BASE) {
		return rcc_apb2_frequency;
	} else {
		return rcc_apb1_frequency;
	}
}

/**
 * @brief Set the peripheral clock source
 * @param periph peripheral of choice, eg XXX_BASE
 * @param sel periphral clock source
 */
void rcc_set_peripheral_clk_sel(uint32_t periph, uint32_t sel)
{
	uint8_t shift;
	uint32_t mask;

	switch (periph) {
		case ADC_BASE:
			shift = RCC_CCIPR_ADCSEL_SHIFT;
			mask = RCC_CCIPR_ADCSEL_MASK;
			break;
		case RNG_BASE:
			shift = RCC_CCIPR_RNGSEL_SHIFT;
			mask = RCC_CCIPR_RNGSEL_MASK;
			break;
		case LPTIM1_BASE:
			shift = RCC_CCIPR_LPTIM1SEL_SHIFT;
			mask = RCC_CCIPR_LPTIMxSEL_MASK;
			break;
		case LPTIM2_BASE:
			shift = RCC_CCIPR_LPTIM2SEL_SHIFT;
			mask = RCC_CCIPR_LPTIMxSEL_MASK;
			break;
		case I2C3_BASE:
			shift = RCC_CCIPR_I2C3SEL_SHIFT;
			mask = RCC_CCIPR_I2CxSEL_MASK;
			break;
		case I2C2_BASE:
			shift = RCC_CCIPR_I2C2SEL_SHIFT;
			mask = RCC_CCIPR_I2CxSEL_MASK;
			break;
		case I2C1_BASE:
			shift = RCC_CCIPR_I2C1SEL_SHIFT;
			mask = RCC_CCIPR_I2CxSEL_MASK;
			break;
		case LPUART1_BASE:
			shift = RCC_CCIPR_LPUART1SEL_SHIFT;
			mask = RCC_CCIPR_LPUART1SEL_MASK;
			break;
		case SPI2S2_BASE:
			shift = RCC_CCIPR_SPI2S2SEL_SHIFT;
			mask = RCC_CCIPR_SPI2S2SEL_MASK;
			break;
		case USART2_BASE:
			shift = RCC_CCIPR_USART2SEL_SHIFT;
			mask = RCC_CCIPR_USARTxSEL_MASK;
			break;
		case USART1_BASE:
			shift = RCC_CCIPR_USART1SEL_SHIFT;
			mask = RCC_CCIPR_USARTxSEL_MASK;
			break;
		default:
			cm3_assert_not_reached();
			return;
	}

	uint32_t reg32 = RCC_CCIPR & ~(mask << shift);
	RCC_CCIPR = reg32 | (sel << shift);
}

/*---------------------------------------------------------------------------*/
/*
 * These functions are setting up the whole clock system for the most common
 * input clock and output clock configurations.
 */
/*---------------------------------------------------------------------------*/
/** @brief RCC Set System Clock PLL at 48MHz from HSI
 *
 */

void rcc_clock_setup_in_hsi_out_48mhz(void) {

	rcc_osc_on(RCC_HSI16);
	rcc_wait_for_osc_ready(RCC_HSI16);
	rcc_set_sysclk_source(RCC_CFGR_SW_HSI16);
	rcc_wait_for_sysclk_status(RCC_HSI16);

	flash_prefetch_enable();
	flash_set_ws(FLASH_ACR_LATENCY_1WS);
	flash_dcache_enable();
	flash_icache_enable();

	rcc_osc_off(RCC_PLL);
	/* 16MHz / 4 = > 4MHz * 48 = 192MHz VCO => /4 => 48MHz main pll  */
	rcc_set_main_pll(RCC_PLLCFGR_PLLSRC_HSI16, 4, 48, 0, 0, 4);
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);

	rcc_set_sysclk_source(RCC_CFGR_SW_PLLR);
	rcc_wait_for_sysclk_status(RCC_PLL);

	rcc_osc_off(RCC_MSI);

	rcc_ahb_frequency = 48e6;
	rcc_apb1_frequency = 48e6;
	rcc_apb2_frequency = 48e6;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set System Clock PLL at 24MHz from HSI
 *
 */

void rcc_clock_setup_in_hsi_out_24mhz(void) {

	rcc_osc_on(RCC_HSI16);
	rcc_wait_for_osc_ready(RCC_HSI16);
	rcc_set_sysclk_source(RCC_CFGR_SW_HSI16);
	rcc_wait_for_sysclk_status(RCC_HSI16);

	flash_prefetch_enable();
	flash_set_ws(FLASH_ACR_LATENCY_0WS);
	flash_dcache_enable();
	flash_icache_enable();

	rcc_osc_off(RCC_PLL);
	/* 16MHz / 4 = > 4MHz * 48 = 192MHz VCO => /8 => 24MHz main pll  */
	rcc_set_main_pll(RCC_PLLCFGR_PLLSRC_HSI16, 4, 48, 0, 0, 8);
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);

	rcc_set_sysclk_source(RCC_CFGR_SW_PLLR);
	rcc_wait_for_sysclk_status(RCC_PLL);

	rcc_osc_off(RCC_MSI);

	rcc_ahb_frequency = 24e6;
	rcc_apb1_frequency = 24e6;
	rcc_apb2_frequency = 24e6;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set System Clock PLL at 12MHz from HSI
 *
 */

void rcc_clock_setup_in_hsi_out_12mhz(void) {

	rcc_osc_on(RCC_HSI16);
	rcc_wait_for_osc_ready(RCC_HSI16);
	rcc_set_sysclk_source(RCC_CFGR_SW_HSI16);
	rcc_wait_for_sysclk_status(RCC_HSI16);

	flash_prefetch_enable();
	flash_set_ws(FLASH_ACR_LATENCY_0WS);
	flash_dcache_enable();
	flash_icache_enable();

	rcc_osc_off(RCC_PLL);
	/* 16MHz / 4 = > 4MHz * 24 = 96MHz VCO => /8 => 12MHz main pll  */
	rcc_set_main_pll(RCC_PLLCFGR_PLLSRC_HSI16, 4, 24, 0, 0, 8);
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);

	rcc_set_sysclk_source(RCC_CFGR_SW_PLLR);
	rcc_wait_for_sysclk_status(RCC_PLL);

	rcc_osc_off(RCC_MSI);

	rcc_ahb_frequency = 12e6;
	rcc_apb1_frequency = 12e6;
	rcc_apb2_frequency = 12e6;
}

/**@}*/
