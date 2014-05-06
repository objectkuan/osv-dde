/*
 * Copyright (C) 2013 Cloudius Systems, Ltd.
 *
 * This work is open source software, licensed under the terms of the
 * BSD license as described in the LICENSE file in the top-level directory.
 */

#include "arch-cpu.hh"
#include "sched.hh"
#include "debug.hh"

namespace sched {

__thread bool in_exception = false;

inline void arch_cpu::enter_exception()
{
    if (in_exception) {
        abort("nested exception");
    }
    in_exception = true;
    auto& s = percpu_exception_stack;
    set_exception_stack(s, sizeof(s));
}

inline void arch_cpu::exit_exception()
{
    set_exception_stack(&thread::current()->_arch);
    in_exception = false;
}

exception_guard::exception_guard()
{
    sched::cpu::current()->arch.enter_exception();
}

exception_guard::~exception_guard()
{
    sched::cpu::current()->arch.exit_exception();
}

}
