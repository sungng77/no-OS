#include <stdio.h>
#include <sleep.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <xil_cache.h>
#include <xparameters.h>
#include <inttypes.h>
#include "xil_printf.h"
#include "i2c.h"
#include "ad7091r5.h"
#include "error.h"
#include "delay.h"

/******************************************************************************/
/********************** Macros and Constants Definitions **********************/
/******************************************************************************/
#define AD7091r5_EVB_SAMPLE_NO			10000

int main()
{
	struct ad7091r5_dev *dev;
	int32_t ret, data, i;

	struct ad7091r5_init_param ad7091r5_init_param = {
		.i2c_init = {
			0,
		},
	};

	print("Test\n\r");

	Xil_ICacheEnable();
	Xil_DCacheEnable();

	ret = ad7091r5_init(&dev, &ad7091r5_init_param);
	if (ret < 0)
		return ret;

	print("Success\n\r");

	return 0;
}
