
## 内存泄漏如何检测，如何解决
[C++内存泄漏的几种情况](http://www.cnblogs.com/SeekHit/p/6549940.html)

[C/C++内存泄漏及检测](https://www.cnblogs.com/skynet/archive/2011/02/20/1959162.html)

## 手撕算法核心思想
搜索：BFS、DFS（状态树、剪枝[可行性剪枝、最优化剪枝]） <--> bottomUp topDown记忆化搜索

动态规划：状态、策略 <--> 状态转移方程 值区间的迭代更新 100以下考虑DP

数据结构：优先队列、堆、栈、Map、Set、并查集、线段树

## mmap
多个进程mmap到同一个文件，实际上就是大家在共享文件page cache中的内存

页缓存是面向文件，面向内存的。通过一系列的数据结构，比如inode, address_space, page，将一个文件映射到页的级别，通过page + offset就可以定位到一个文件的具体位置

## 数字存储
十进制数-25的原码为10011001，反码为11100110，补码是反码加1，即为11100111，转化为十六进制即为E7

## 内存碎片
内碎片是已被分配出去但是用不到的内存空间，外碎片是由于大小太小而无法分配出去的空闲块

## 类型转换
```c++
static_cast 基本类型转换，且基类指针转派生类没有类型安全检查
dynamic_cast 主要用于类层次间的上行转换和下行转换，还可以用于类之间的交叉转换。在类层次间进行上行转换时，dynamic_cast和static_cast的效果是一样的；在进行下行转换时，dynamic_cast具有类型检查的功能,比static_cast更安全。
reinterpret_cast用在任意指针（或引用）类型之间的转换
该运算符用来修改类型的const或volatile属性
```

## RTTI
RTTI（Run-Time Type Identification) 运行时类型识别。

当类中含有虚函数时，其基类的指针就可以指向任何派生类的对象，这时就有可能不知道基类指针到底指向的是哪个对象的情况，类型的确定要在运行时利用运行时类型标识做出。使用内建的 RTTI 中的运算符：typeid 和 dynamic_cast。

## 为什么需要长连接
可以实现连接复用，只是需要心跳包来keep live

## kill 与 kill -9
kill pid的作用是向进程号为pid的进程发送SIGTERM（这是kill默认发送的信号），该信号是一个结束进程的信号且可以被应用程序捕获。若应用程序没有捕获并响应该信号的逻辑代码，则该信号的默认动作是kill掉进程。这是终止指定进程的推荐做法。
 
kill -9 pid则是向进程号为pid的进程发送SIGKILL（该信号的编号为9），从本文上面的说明可知，SIGKILL既不能被应用程序捕获，也不能被阻塞或忽略，其动作是立即结束指定进程。通俗地说，应用程序根本无法“感知”SIGKILL信号，即exit，它在完全无准备的情况下，就被收到SIGKILL信号的操作系统给干掉了，显然，在这种“暴力”情况下，应用程序完全没有释放当前占用资源的机会。事实上，SIGKILL信号是直接发给init进程的，它收到该信号后，负责终止pid指定的进程。在某些情况下（如进程已经hang死，无法响应正常信号），就可以使用kill -9来结束进程。
若通过kill结束的进程是一个创建过子进程的父进程，则其子进程就会成为孤儿进程（Orphan Process）

## 内核线程与用户线程
![xx](http://img.blog.csdn.net/20160712204159672)

[线程的3种实现方式--内核级线程, 用户级线程和混合型线程](http://blog.csdn.net/gatieme/article/details/51892437)

## 线程安全
有多个线程在同时运行，如果每次运行结果和单线程运行的结果是一样的，而且其他的变量的值也和预期的是一样的，就是线程安全的。

## 自旋锁
在单处理机环境中可以使用特定的原子级汇编指令swap和test_and_set实现进程互斥。为在多CPU环境中利用test_and_set指令实现进程互斥，硬件需要提供进一步的支持，以保证test_and_set指令执行的原子性. 这种支持目前多以“锁总线”(bus locking)的形式提供的，由于test_and_set指令对内存的两次操作都需要经过总线，在执行test_and_set指令之前锁住总线，在执行test_and_set指令后开放总线，即可保证test_and_set指令执行的原子性，

## Linux命令
```bash
wc [OPTION] [FILE] --> -c, --bytes; -l, --lines; -w, words
find /home -name "*.txt"
grep "match_pattern" file_1 file_2 file_3 ...

# 使用正则表达式 -E 选项：
grep -E "[1-9]+"
# 或
egrep "[1-9]+"

# 只输出文件中匹配到的部分 -o 选项
echo this is a test line. | grep -o -E "[a-z]+\."

# ln oldfile newfile
ln -s /usr/mengqc/mub1 /usr/liu/abc

top 动态显示当前耗费资源最多进程信息
ps 显示瞬间进程状态 ps -aux
du 查看目录大小 du -h /home带有单位显示目录信息
df 查看磁盘大小 df -h 带有单位显示磁盘信息

alias showmeit="ps -aux"

# 查看机器端口占用情况
netstat -ano 

sudo dpkg -i tree_1.5.3-1_i386.deb 安装软件
sudo dpkg -r tree 卸载软件

# vim命令模式下
/apache 在文档中查找apache 按n跳到下一个，shift+n上一个
:set number 显示行号
:set nonumber 隐藏行号

/etc/profile 系统环境变量
bash_profile 用户环境变量
.bashrc 用户环境变量
su user 切换用户，加载配置文件.bashrc
su - user 切换用户，加载配置文件/etc/profile ，加载bash_profile

# 更改文件的用户及用户组
sudo chown [-R] owner[:group] {File|Directory}
sudo chown root:root jdk-7u21-linux-i586.tar.gz
```

## 内存对齐
满足两条规则，1每个成员的偏移量都必须是当前成员所占内存大小的整数倍，如果不是，编译器会在成员之间填上字节；2当所有成员计算完成之后，编译器判断当前结构体大小是否是结构体中最宽成员变量大小的整数倍，如果不是会在最后一个成员后做字节填充。
```c++
struct _THUNDER{
       int iVersion;
       char cTag;
       char cAdv;
       int iUser;
       char cEnd;
}Thunder;
int sz = sizeof(Thunder); //16

|----------int----------|
|char|char|char|char|
|----------int----------|
|char|char|char|char|
```

## C++
```c++
size_t 是 unsigned 类型，用于指明数组长度或下标，它必须是一个正数， std::size_t
ptrdiff_t 是 signed 类型，用于存放同一数组中两个指针之间的差距，它可以是负数， std::ptrdiff_t
size_type 是 unsigned 类型 , 表示容器中元素长度或者下标， vector<int>::size_type i = 0
difference_type 是 signed 类型 , 表示迭代器差距， vector<int>:: difference_type = iter1-iter2
```
前二者位于标准类库 std 内，后二者专为 STL 对象所拥有。

## static
static 文件作用域，内存分配，函数内部生命周期，C++中成员函数和成员变量，this指针，初始化位置等

## 内存
一般来说，IA-32体系结构中进程空间的代码段从0x08048000开始，这与最低可用地址(0x00000000)有128M的间距，按照linux内核架构一书介绍是为了捕获NULL指针(具体不详)

大多数操作系统中，极小的地址通常都是不允许访问的，如NULL。C语言将无效指针赋值为0也是出于这种考虑，因为0地址上正常情况下不会存放有效的可访问数据。

据我所知，这个数字没什么特殊含义，这个数值就是大佬们拍脑袋定的。
文档里说：虚拟内存不从0开始是为了可以预留一个足够大的read only堆，每个程序都可以在这里建立单独的2级页表。一个2级页表是0x00400000

已初始化的全局变量保存在.data 段中，未初始化的全局变量保存在.bss 段中

![xx](https://pic1.zhimg.com/80/2f37e45940205cddfc0cfc529347f05f_hd.jpg)

## 序列化
序列化(serialization)机制能够将一个实例对象的状态信息写入到一个字节流中，使其可以通过socket进行传输、或者持久化存储到数据库或文件系统中；然后在需要的时候，可以读取字节流中的信息来重构一个相同的对象。

so，序列化一般用于以下场景： 
1：永久性保存对象，保存对象的字节序列到本地文件或者数据库中

2：通过序列化以字节流的形式使对象在网络中进行传递和接收；

3：通过序列化在进程间传递对象。

## 系统调用
![xx](http://images2015.cnblogs.com/blog/745208/201603/745208-20160320173759365-717123393.jpg)

x,y,z就是函数，系统调用应用程序编程接口，这个应用程序编程接口里面封装了一个系统调用，这会触发一个0x80的一个中断，这个中断向量就对应着SYSTEM_CALL这个内核代码的入口的起点，sys_xyz是对应的中断服务程序，在中断服务程序执行完之后，它可能会ret_from_sys_call， 之后就经过这个函数进行处理， 这是一个进程调度的时机，如果没有发生进程调度，它就会ireturn可能就会返回到用户态接着执行。

中断向量0x80与system_call绑定起来;系统调用号将xyz和sys_xyz关联起来,进程必须指明需要哪些系统调用，这需要传递一个系统调用号的参数，使用eax寄存器

用户态切换到内核态的三种方式：
1. 系统调用
2. 异常
3. 外围设备中断

## Linux进程调度时机
1. 进程状态转换的时刻：进程终止、进程睡眠；
2. 当前进程的时间片用完时（current->counter=0）；
3. 设备驱动程序
4. 进程从中断、异常及系统调用返回到用户态时；
时机1，进程要调用sleep（）或exit（）等函数进行状态转换，这些函数会主动调用调度程序进行进程调度；

时机2，由于进程的时间片是由时钟中断来更新的，因此，这种情况和时机4是一样的。

时机3，当设备驱动程序执行长而重复的任务时，直接调用调度程序。在每次反复循环中，驱动程序都检查need_resched的值，如果必要，则调用调度程序schedule()主动放弃CPU。

时机4，如前所述，不管是从中断、异常还是系统调用返回，最终都调用ret_from_sys_call（），由这个函数进行调度标志的检测，如果必要，则调用调用调度程序。那么，为什么从系统调用返回时要调用调度程序呢？这当然是从效率考虑。从系统调用返回意味着要离开内核态而返回到用户态，而状态的转换要花费一定的时间，因此，在返回到用户态前，系统把在内核态该处理的事全部做完。

每个时钟中断（timer interrupt）发生时，由三个函数协同工作，共同完成进程的选择和切换，它们是：schedule（）、do_timer（）及ret_form_sys_call（）。我们先来解释一下这三个函数：
1. schedule（）：进程调度函数，由它来完成进程的选择（调度）；
2. do_timer（）：暂且称之为时钟函数，该函数在时钟中断服务程序中被调用，是时钟中断服务程序的主要组成部分，该函数被调用的频率就是时钟中断的频率即每秒钟100次（简称100赫兹或100Hz）；
3. ret_from_sys_call（）：系统调用返回函数。当一个系统调用或中断完成时，该函数被调用，用于处理一些收尾工作，例如信号处理
