#!/usr/bin/env python

from waflib import Configure, Options
Configure.autoconfig = True

def options(opt):
    opt.load("compiler_c gnu_dirs")

def configure(conf):
    conf.load("compiler_c gnu_dirs")

    conf.env.append_unique("DEFINES", ["_GNU_SOURCE"])
    conf.env.append_unique("CFLAGS", ["-std=gnu99", "-O2", "-Wall",
                                      "-Werror", "-g"])

    conf.check_cc(fragment="int main() { return 0; }\n",
                  msg="Checking for working compiler")



def build(bld):
    bld.stlib(source=bld.path.ant_glob("src/*.c"),
              includes="inc/argconfig",
              target="argconfig",
              install_path="${PREFIX}/lib")

    bld.install_files("${PREFIX}/include/argconfig",
                      bld.path.ant_glob("inc/argconfig/*.h"))
