#ifndef _IR_I2C
#define _IR_I2C

#include <media/ir-common.h>

struct IR_i2c;

struct IR_i2c {
	IR_KEYTAB_TYPE         *ir_codes;
	struct i2c_client      c;
	struct input_dev       *input;
	struct ir_input_state  ir;

	/* Used to avoid fast repeating */
	unsigned char          old;

	struct delayed_work    work;
	char                   phys[32];
	int                    (*get_key)(struct IR_i2c*, u32*, u32*);
};
#endif
