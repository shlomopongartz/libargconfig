

from waflib import Configure, Options
Configure.autoconfig = True

def options(opt):
    opt.load("compiler_c gnu_dirs")

def configure(conf):
    conf.load("compiler_c gnu_dirs")

    conf.env.INCLUDES = ["inc"]
    conf.env.CXXFLAGS = ["-O2", "-Wall", "-Werror", "-g"]
    conf.env.CFLAGS = conf.env.CXXFLAGS + ["-std=gnu99", "-D_GNU_SOURCE"]

    conf.check_cc(fragment="int main() { return 0; }\n")



def build(bld):
    bld.stlib(source=bld.path.ant_glob("src/*.c"),
              target="argconfig",
              install_path="${PREFIX}/lib")

    bld.install_files("${PREFIX}/include/argconfig",
                      bld.path.ant_glob("inc/argconfig/*.h"))
