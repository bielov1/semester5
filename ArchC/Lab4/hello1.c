// SPDX-License-Identifier: GPL-2-Clause
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
struct my_struct {
    struct list_head tlist;
    ktime_t before_print;
    ktime_t after_print;
};

static LIST_HEAD(my_list_head);

int print_hello(void)
{
    struct my_struct *node = kmalloc(sizeof(*node), GFP_KERNEL);
    if (!node) {
        return -ENOMEM;
    }
    node->before_print = ktime_get();
    pr_info("Hello, WORLD!\n");
    node->after_print = ktime_get();

    list_add(&node->tlist, &my_list_head);
    return 0;
}
EXPORT_SYMBOL(print_hello);



static __init int hello1_init(void) {
    return 0;
}


static void hello1_exit(void) {
    struct my_struct *current_node, *tmp;

    list_for_each_entry_safe(current_node, tmp, &my_list_head, tlist) {
        s64 time_diff = ktime_to_ns(ktime_sub(current_node->after_print, current_node->before_print));
        pr_info("Time taken for print: %lld ns\n", time_diff);

        list_del(&current_node->tlist);
        kfree(current_node);
    }

    pr_info("hello1 module unloaded\n");
}

module_init(hello1_init);
module_exit(hello1_exit);
