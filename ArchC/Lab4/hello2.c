
/*
 * Copyright (c) 2017, GlobalLogic Ukraine LLC
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    This product includes software developed by the GlobalLogic.
 * 4. Neither the name of the GlobalLogic nor the
 *    names of its contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY GLOBALLOGIC UKRAINE LLC ``AS IS`` AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL GLOBALLOGIC UKRAINE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <hello1.h>


MODULE_AUTHOR("Oleh Bielov, IO-11, olaph22@gmail.com");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");


static uint howmany = 1;

//WARNING: Symbolic permissions 'S_IRUGO' are not preferred. Consider using octal permissions '0444'.
module_param(howmany, uint, 0444);
MODULE_PARM_DESC(howmany, "how many time to print hello");

int i;
static int hello2_init(void) {
    if (howmany == 0) {
        pr_warn("WARNING! Inserted parameter is 0\n");
    } else if (howmany >= 5 && howmany <= 10){
        pr_warn("WARNING! Inserted parameter is between 5 and 10\n");
    } else if (howmany > 10) {
        pr_err("ERROR! Inserted parameter is greater than 10. Parameter cannot be greater than 10");
        return -EINVAL; //помилка
    }

    for (i = 0; i < howmany; i++) {
        print_hello();
    }
    return 0;
}

static void hello2_exit(void) {
    pr_info(KERN_ALERT "Goodbye!\n");
}

module_init(hello2_init);
module_exit(hello2_exit);
