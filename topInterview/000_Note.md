## 内存泄漏如何检测，如何解决
[C++内存泄漏的几种情况](http://www.cnblogs.com/SeekHit/p/6549940.html)

[C/C++内存泄漏及检测](https://www.cnblogs.com/skynet/archive/2011/02/20/1959162.html)

## 数字存储
十进制数-25的原码为10011001，反码为11100110，补码是反码加1，即为11100111，转化为十六进制即为E7

## 内存碎片
内碎片是已被分配出去但是用不到的内存空间，外碎片是由于大小太小而无法分配出去的空闲块

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
3. ret_from_sys_call（）：系统调用返回函数。当一个系统调用或中断完成时，该函数被调用，用于处理一些收尾工作，例如信号处理、核心任务等等。

## UDP和TCP的区别
![xx](http://img.my.csdn.net/uploads/201303/15/1363304805_1611.jpg)

![xx](http://img.my.csdn.net/uploads/201303/15/1363304832_2419.jpg)

![xx](http://img.blog.csdn.net/20170227111849763?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvTWFyeTE5OTIwNDEw/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center)

## 数据库优化
找瓶颈，数据库吞吐量上不去或者查询慢都是因为某一瓶颈的存在，从非常大的粒度来看，瓶颈可以分为五类：io 内存 CPU 网络 锁。

[分库分表的几种常见形式以及可能遇到的难](http://www.infoq.com/cn/articles/key-steps-and-likely-problems-of-split-table)

1、 表的设计要规范，即要符合数据库设计三范式。2、 适当建立索引，在频繁作为检索条件，更新较少的字段上建立索引，以提高查询速度。3、 分表查询，有水平分割、垂直分割。4、 读写分离，读(read)、写(create、update、delete)。5、建立存储过程。

查看执行计划Explain Plan，避免全表扫描；缓存

[面试技巧，如何通过索引说数据库优化能力](http://www.broadview.com.cn/article/771)

## tcp三次握手四次挥手，TCP 拥塞控制等
![xx](http://oowjr8zsi.bkt.clouddn.com/%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20180212114856.jpg)

![xx](http://img.blog.csdn.net/20140509221015859?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQveWVjaGFvZGVjaHVudGlhbg==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

`Nagle算法`
TCP/IP协议中，无论发送多少数据，总是要在数据前面加上协议头，同时，对方接收到数据，也需要发送ACK表示确认。为了尽可能的利用网络带宽，TCP总是希望尽可能的发送足够大的数据。（一个连接会设置MSS参数，因此，TCP/IP希望每次都能够以MSS尺寸的数据块来发送数据）。Nagle算法就是为了尽可能发送大块数据，避免网络中充斥着许多小数据块。

Nagle算法的基本定义是任意时刻，最多只能有一个未被确认的小段。 所谓“小段”，指的是小于MSS尺寸的数据块，所谓“未被确认”，是指一个数据块发送出去后，没有收到对方发送的ACK确认该数据已收到。

Nagle是基于ack的,当发送端没有收到ack的时候,会尽可能的合并小包。它并不管包的大小，因此它事实上就是一个扩展的停-等协议，只不过它是基于包停-等的，而不是基于字节停-等的。Nagle算法完全由TCP协议的ACK机制决定，这会带来一些问题，比如如果对端ACK回复很快的话，Nagle事实上不会拼接太多的数据包

## 各种排序算法的时间复杂度和稳定性

## Java与C++区别
指针、操作符重载、GC、跨平台性

## [硬链接与软链接](https://www.ibm.com/developerworks/cn/linux/l-cn-hardandsymb-links/)
[符号连接、软连接、硬连接、快捷方式、副本(copy)之间有何区别和联系？ - 高洪涛的回答 - 知乎](https://www.zhihu.com/question/20729978/answer/31351994)

![xx](https://images2015.cnblogs.com/blog/393890/201511/393890-20151128142803015-292063645.png)

![xx](https://images2015.cnblogs.com/blog/393890/201511/393890-20151123155409373-499496841.png)

## [阿里杭州站C++研发面经](http://www.zheyibu.com/article/4836.html)

## [阿里实习生C/C++研发内推三面+专场三面](https://www.nowcoder.com/discuss/5773)

## RVO/NRVO(named return value optimation) 当局部临时对象被构造的时候，直接被构造在将要拷贝/移动到的对象上，省去了拷贝和移动构造

## 进程 线程区别
定义方面：进程是程序在某个数据集合上的一次运行活动；线程是进程中的一个执行路径。进程可以说是程序在内存中的一种表现形式，程序存储在硬盘上属于静态文件结构，进程就是程序动态运行的实例，它是承担分配系统资源的实体，包括一些meta data记录运行状态，比如task_struct
1. 标识符：与进程相关的唯一标识符，用来区别正在执行的进程和其他进程。
2. 状态：描述进程的状态，因为进程有挂起，阻塞，运行等好几个状态，所以都有个标识符来记录进程的执行状态。
3. 优先级：如果有好几个进程正在执行，就涉及到进程被执行的先后顺序的问题，这和进程优先级这个标识符有关。
4. 程序计数器：程序中即将被执行的下一条指令的地址。
5. 内存指针：程序代码和进程相关数据的指针。
6. 上下文数据：进程执行时处理器的寄存器中的数据。
7. I/O状态信息：包括显示的I/O请求，分配给进程的I/O设备和被进程使用的文件列表等。
8. 记账信息：包括处理器的时间总和，记账号等等。

角色方面：在支持线程机制的系统中，进程是系统资源分配的单位，线程是系统调度的单位。

资源共享方面：进程之间不能共享资源，而线程共享所在进程的地址空间和其它资源。同时线程还有自己的栈和栈指针，程序计数器等寄存器。

独立性方面：进程有自己独立的地址空间，而线程没有，线程必须依赖于进程而存在。

在Linux中，线程是由进程来实现。在内核里面，进程用 struct task_struct 表示，一个进程就是一个 task_struct，一个线程也是一个 task_struct，但是同一个进程中的线程的 task_struct 里边某些值相同，某些指针指向相同的位置。从内核的角度来看，线程就是进程。

不论什么进程(系统或用户)，它们都是在操作系统内核的支持下完成的，与内核紧密相关，不能离开内核。
进程中可以包括内核支持线程和用户级线程。其中，
内核支持线程：它就是在内核的支持下运行的，离不开内核，系统在内核空间为每一个内核支持线程设置一个线程控制块，内核通过此块来感知线程存在，并加以控制它。
用户级线程   ： 它仅存在于用户空间，对于这种线程的创建、撤消、线程之间的同步与通信等功能，都无须利用系同调用来实现(无须内核支持控制)。一般为一个应用进程创建较多的用户线程，线程之间的切换和调用比进程要快和简单，这些线程的任务控制块都存在用户空间，内核完全不知道用户级线程的存在。

## 进程调度
[O(n)、O(1)和CFS调度器](http://www.wowotech.net/process_management/scheduler-history.html)

[Linux进程调度-------O(1)调度和CFS调度器](http://blog.csdn.net/a2796749/article/details/47101533)

## 线程同步：互斥锁、条件变量、信号量
[线程同步：互斥锁，条件变量，信号量](http://www.cnblogs.com/549294286/p/3687678.html)

内核信号量的构成

内核信号量类似于自旋锁，因为当锁关闭着时，它不允许内核控制路径继续进行。然而，当内核控制路径试图获取内核信号量锁保护的忙资源时，相应的进程就被挂起。只有在资源被释放时，进程才再次变为可运行。 
只有可以睡眠的函数才能获取内核信号量；中断处理程序和可延迟函数都不能使用内核信号量。 
内核信号量是struct semaphore类型的对象，在内核源码中位于include\linux\semaphore.h文件

struct semaphore
{
　　 atomic_t count;
　　 int sleepers;
　　 wait_queue_head_t wait;
}

## 进程通信：管道、消息队列、共享内存、信号、套接字

## 红黑树
但它是如何保证一棵n个结点的红黑树的高度始终保持在logn的呢？这就引出了红黑树的5个性质：
* 每个结点要么是红的要么是黑的。  
* 根结点是黑的。  
* 每个叶结点（叶结点即指树尾端NIL指针或NULL结点）都是黑的。  
* 如果一个结点是红的，那么它的两个儿子都是黑的。  
* 对于任意结点而言，其到叶结点树尾端NIL指针的每条路径都包含相同数目的黑结点。 

1. 如果插入一个node引起了树的不平衡，AVL和RB-Tree都是最多只需要2次旋转操作，即两者都是O(1)；但是在删除node引起树的不平衡时，最坏情况下，AVL需要维护从被删node到root这条路径上所有node的平衡性，因此需要旋转的量级O(logN)，而RB-Tree最多只需3次旋转，只需要O(1)的复杂度。

2. 其次，AVL的结构相较RB-Tree来说更为平衡，在插入和删除node更容易引起Tree的unbalance，因此在大量数据需要插入或者删除时，AVL需要rebalance的频率会更高。因此，RB-Tree在需要大量插入和删除node的场景下，效率更高。自然，由于AVL高度平衡，因此AVL的search效率更高。

3. map的实现只是折衷了两者在search、insert以及delete下的效率。总体来说，RB-tree的统计性能是高于AVL的。


[知乎专栏-红黑树的删除](https://zhuanlan.zhihu.com/p/22800206)

[wiki_红黑树](https://zh.wikipedia.org/wiki/%E7%BA%A2%E9%BB%91%E6%A0%91)

[wiki_二叉搜索树](https://zh.wikipedia.org/wiki/%E4%BA%8C%E5%85%83%E6%90%9C%E5%B0%8B%E6%A8%B9)

[wiki_AVL树](https://zh.wikipedia.org/wiki/AVL%E6%A0%91)

[wiki_红黑树](https://zh.wikipedia.org/wiki/%E7%BA%A2%E9%BB%91%E6%A0%91)

BST删除结点：叶子结点；左子树空或者右子树空；左右都非空，左最大或右最小代替当前结点

红黑树相对于AVL树的删除效率较高，AVL删除结点的算法可以参见BST的删除结点，但是删除之后必须检查从删除结点开始到根结点路径上的所有结点的平衡因子。因此删除的代价稍微要大一些。每一次删除操作最多需要O(logN)次旋转。因此，删除操作的时间复杂度为O(logN)+O(logN)=O(2logN)；而红黑树删除一个结点最多只需要3次旋转操作。

两者的查找代价都在O(logN)，AVL树每一次插入数据使得AVL中某些结点的平衡因子，左子树减去右子树的高度差，超过1就必须进行旋转操作，最多进行两次旋转；红黑树插入结点时，需要旋转操作和变色操作，最多只需要2次旋转，这一点和AVL的插入操作一样。虽然变色操作需要O(logN)，但是变色操作十分简单，代价很小。

对于在内存中的查找结构而言，红黑树的效率已经非常好了。但是如果是数据量非常大的查找呢？将这些数据全部放入内存组织成红黑树结构显然是不实际的。实际上，像OS中的文件目录存储，数据库中的文件索引结构的存储.... 都不可能在内存中建立查找结构。必须在磁盘中建立好这个结构。
在磁盘中组织查找结构，从任何一个结点指向其他结点都有可能读取一次磁盘数据，再将数据写入内存进行比较。大家都知道，频繁的磁盘IO操作，效率是很低下的(机械运动比电子运动要慢不知道多少)。显而易见，所有的二叉树的查找结构在磁盘中都是低效的。因此，B树很好的解决了这一个问题。

通常的说法是：内存访问速度是纳秒级(24-93ns)，磁盘的访问速度是毫秒级(13.0ms)，SSD的速度是微妙级别(30-300us)

`B树`

![xx](http://img.my.csdn.net/uploads/201106/7/8394323_13074405906V6Q.jpg)

`B+树`

![xx](http://www.niceru.com/wp-content/uploads/2013/09/2.png)

B+树非叶子结点不包含磁盘文件等信息，磁盘代价更低；任何关键字的查找必须走一条从根结点到叶子结点的路，所有关键字查询的路径长度相同，导致每一个数据的查询效率相当；B+树只需要遍历叶子节点就可以解决对全部关键字信息的扫描，所以对于数据库中频繁使用的range query，范围查询，B+树有着更高的性能

[二叉查找树，红黑树，AVL树，B~/B+树(B-tree)，伸展树——优缺点及比较](http://blog.csdn.net/bytxl/article/details/40920165)

[理解B+树算法和Innodb索引](http://www.niceru.com/topic/420.html)

## 产生死锁的四个必要条件？
* 互斥条件：进程对所分配到的资源不允许其他进程进行访问，若其他进程访问该资源，只能等待，直至占有该资源的进程使用完成后释放该资源
* 请求和保持条件：进程获得一定的资源之后，又对其他资源发出请求，但是该资源可能被其他进程占有，此事请求阻塞，但又对自己获得的资源保持不放
* 不可剥夺条件：是指进程已获得的资源，在未完成使用之前，不可被剥夺，只能在使用完后自己释放
* 环路等待条件：是指进程发生死锁后，必然存在一个进程--资源之间的环形链

## 处理死锁的基本方法
* 预防死锁：通过设置一些限制条件，去破坏产生死锁的必要条件
* 避免死锁：在资源分配过程中，使用某种方法避免系统进入不安全的状态，从而避免发生死锁
* 检测死锁：允许死锁的发生，但是通过系统的检测之后，采取一些措施，将死锁清除掉
* 解除死锁：该方法与检测死锁配合使用

死锁预防是破坏死锁发生的条件，从而达到避免死锁的发生：1.破坏互斥条件2.破坏占有和等待条件3.破坏不可抢占条件4.破坏环路等待条件


## m阶B树
* 根结点至少有两个子女；
* 每个非根节点所包含的关键字个数 j 满足：┌m/2┐ - 1 <= j <= m - 1；
* 除根结点以外的所有结点（不包括叶子结点）的度数正好是关键字总数加1，故内部子树个数 k 满足：┌m/2┐ <= k <= m ；
* 所有的叶子结点都位于同一层。

在B-树中，每个结点中关键字从小到大排列，并且当该结点的孩子是非叶子结点时，该k-1个关键字正好是k个孩子包含的关键字的值域的分划。
因为叶子结点不包含关键字，所以可以把叶子结点看成在树里实际上并不存在外部结点，指向这些外部结点的指针为空，叶子结点的数目正好等于树中所包含的关键字总个数加1。

B-树中的一个包含n个关键字，n+1个指针的结点的一般形式为： （n,P0,K1,P1,K2,P2,…,Kn,Pn）
其中，Ki为关键字，K1<K2<…<Kn, Pi 是指向包括Ki到Ki+1之间的关键字的子树的指针。

## hashmap.hashtable 区别，怎样设计实现一个高效的线程安全的hashmap 

## 给定a、b两个文件，各存放50亿个url，每个url各占用64字节，内存限制是4G，如何找出a、b文件共同的url？
可以估计每个文件的大小为5G*64=300G，远大于4G。所以不可能将其完全加载到内存中处理。考虑采取分而治之的方法。 遍历文件a，对每个url求取hash(url)%1000，然后根据所得值将url分别存储到1000个小文件（设为a0,a1,...a999）当中。这样每个小文件的大小约为300M。遍历文件b，采取和a相同的方法将url分别存储到1000个小文件(b0,b1....b999)中。这样处理后，所有可能相同的url都在对应的小文件(a0 vs b0, a1 vs b1....a999 vs b999)当中，不对应的小文件（比如a0 vs b99）不可能有相同的url。然后我们只要求出1000对小文件中相同的url即可。 比如对于a0 vs b0，我们可以遍历a0，将其中的url存储到hash_map当中。然后遍历b0，如果url在hash_map中，则说明此url在a和b中同时存在，保存到文件中即可。 如果分成的小文件不均匀，导致有些小文件太大（比如大于2G），可以考虑将这些太大的小文件再按类似的方法分成小小文件即可。

## 根据每个订单的商品做hash, 分成小文件 做统计,   再用堆排序取top100

## 缓存服务器
一致性、平衡性

![hash](http://www.codeproject.com/KB/recipes/lib-conhash/virtual.JPG)

基本思想就是将对象和 cache 都映射到同一个 hash 数值空间中，并且使用相同的hash 算法。 cache 的 hash 计算，一般的方法可以使用 cache 机器的 IP 地址或者机器名作为hash 输入。

![hash](http://www.codeproject.com/KB/recipes/lib-conhash/map.JPG)

请问虚拟节点，怎么保证均匀分布在，那个环上呢？

这就要由hash算法来保证了，均匀分布是概率上的均匀，当虚拟节点足够时，就能保证大概均匀了

## 从很长的数据流等概率随机采样
[蓄水池抽样](http://blog.csdn.net/yangliuy/article/details/43924581)
```python
import random  
SAMPLE_COUNT = 10  
   
# Force the value of the seed so the results are repeatable  
random.seed(12345)  
   
sample_titles = []  
for index, line in enumerate(open("enwiki-20091103-all-titles-in-ns0")):  
        # Generate the reservoir  
        if index < SAMPLE_COUNT:  
                sample_titles.append(line)  
        else:  
                # Randomly replace elements in the reservoir  
                # with a decreasing probability.  
                # Choose an integer between 0 and index (inclusive)  
                r = random.randint(0, index)  
                if r < SAMPLE_COUNT:  
                        sample_titles[r] = line  
print sample_titles  
```

## shuffle
这里的方法是在每次迭代时交换这个被取出的数字到原始列表的最后

```bash
-- To shuffle an array a of n elements (indices 0..n-1):
for i from n−1 downto 1 do
     j ← random integer such that 0 ≤ j ≤ i
     exchange a[j] and a[i]
```

## shell脚本抽取制定字符串、grep+awk+cut+sed
[shell脚本抽取制定字符串、grep+awk+cut+sed](http://blog.csdn.net/zhangfn2011/article/details/39890875)

## 读写锁
[实现线程读写锁的四种方法](http://blog.csdn.net/ojshilu/article/details/25244389)

## 自旋锁
[自旋锁代替互斥锁的实践](http://ifeve.com/practice-of-using-spinlock-instead-of-mutex/)

## 52张扑克牌，红桃A和黑桃A同时被一个人拿到的概率
[52张扑克牌，红桃A和黑桃A同时被一个人拿到的概率](http://blog.csdn.net/huntinux/article/details/16844941)

## 面经
[面试题干货在此 ](https://www.nowcoder.com/discuss/57978?type=0&order=0&pos=24&page=1)

[如何学好 Linux、C++，并搞定 BAT 面试](http://gitbook.cn/books/59c332b1a9dfc23551ebfa4a/index.html)

## select poll epoll
![xx](http://img.blog.csdn.net/20160422143642896)

## 同步与异步 阻塞与非阻塞
同步和异步关注的是消息通信机制 (synchronous communication/ asynchronous communication)

所谓同步，就是在发出一个`调用`时，在没有得到结果之前，该`调用`就不返回。但是一旦调用返回，就得到返回值了。换句话说，就是由`调用者`主动等待这个`调用`的结果。而异步则是相反，`调用`在发出之后，这个调用就直接返回了，所以没有返回结果。换句话说，当一个异步过程调用发出后，调用者不会立刻得到结果。而是在`调用`发出后，`被调用者`通过状态、通知来通知调用者，或通过回调函数处理这个调用。

阻塞和非阻塞关注的是程序在等待调用结果（消息，返回值）时的状态

阻塞调用是指调用结果返回之前，当前线程会被挂起。调用线程只有在得到结果之后才会返回。
非阻塞调用指在不能立刻得到结果之前，该调用不会阻塞当前线程。

![xx](http://static.zybuluo.com/zhenlanghuo/aal4brj3okthdticuenp4vco/5%E7%A7%8DIO%E6%A8%A1%E5%9E%8B%E6%AF%94%E8%BE%83.png)

在处理 IO 的时候，阻塞和非阻塞都是同步 IO。只有使用了特殊的 API 才是异步 IO。
![xx](https://pic4.zhimg.com/80/7d3eb389b7724878bd7e12ebc6dbcdb5_hd.jpg)

[并发模型](https://github.com/linw7/TKeed/blob/master/%E5%B9%B6%E5%8F%91%E6%A8%A1%E5%9E%8B.md)

## 消息队列应用场景
异步：用户注册后，需要发注册邮件和注册短信。用户的响应时间相当于是注册信息写入数据库的时间。注册邮件，发送短信写入消息队列后，直接返回

解耦：用户下单后，订单系统需要通知库存系统。传统模式假如库存系统无法访问，则订单减库存将失败，从而导致订单失败
* 订单系统：用户下单后，订单系统完成持久化处理，将消息写入消息队列，返回用户订单下单成功。
* 库存系统：订阅下单的消息，采用拉/推的方式，获取下单信息，库存系统根据下单信息，进行库存操作。
* 假如：在下单时库存系统不能正常使用。也不影响正常下单，因为下单后，订单系统写入消息队列就不再关心其他的后续操作了。实现订单系统与库存系统的应用解耦。

流量削锋：一般在秒杀或团抢活动中使用广泛，秒杀活动，一般会因为流量过大，导致流量暴增，应用挂掉。为解决这个问题，一般需要在应用前端加入消息队列
1. 可以控制活动的人数；
2. 可以缓解短时间内高流量压垮应用；
3. 用户的请求，服务器接收后，首先写入消息队列。假如消息队列长度超过最大数量，则直接抛弃用户请求或跳转到错误页面；
4. 秒杀业务根据消息队列中的请求信息，再做后续处理

日志处理：日志处理是指将消息队列用在日志处理中，比如Kafka的应用，解决大量日志传输的问题。
* 日志采集客户端，负责日志数据采集，定时写受写入Kafka队列；
* Kafka消息队列，负责日志数据的接收，存储和转发；
* 日志处理应用：订阅并消费kafka队列中的日志数据

消息通讯：比如实现点对点消息队列，或者聊天室等
* 点对点通讯：客户端A和客户端B使用同一队列，进行消息通讯。
* 聊天室通讯：客户端A，客户端B，客户端N订阅同一主题，进行消息发布和接收。实现类似聊天室效果。
以上实际是消息队列的两种消息模式，点对点或发布订阅模式。

## 分布式Session共享解决方案
session往往隐含着面向连接和保持状态这样两个含义

1、session复制
session复制是早期的企业级的使用比较多的一种服务器集群session管理机制。应用服务器开启web容器的session复制功能，在集群中的几台服务器之间同步session对象，使得每台服务器上都保存所有的session信息，这样任何一台宕机都不会导致session的数据丢失，服务器使用session时，直接从本地获取。
这种方式在应用集群达到数千台的时候，就会出现瓶颈，每台都需要备份session，出现内存不够用的情况。

2、session绑定
利用hash算法，比如nginx的ip_hash,使得同一个Ip的请求分发到同一台服务器上。
这种方式不符合对系统的高可用要求，因为一旦某台服务器宕机，那么该机器上的session也就不复存在了，用户请求切换到其他机器后么有session，无法完成业务处理。

3、利用cookie记录session
session记录在客户端，每次请求服务器的时候，将session放在请求中发送给服务器，服务器处理完请求后再将修改后的session响应给客户端。这里的客户端就是cookie。
利用cookie记录session的也有缺点，比如受cookie大小的限制，能记录的信息有限；每次请求响应都需要传递cookie，影响性能，如果用户关闭cookie，访问就不正常。但是由于
cookie的简单易用，可用性高，支持应用服务器的线性伸缩，而大部分要记录的session信息比较小，因此事实上，许多网站或多或少的在使用cookie记录session。

4、session服务器
session服务器可以解决上面的所有的问题，利用独立部署的session服务器（集群）统一管理session，服务器每次读写session时，都访问session服务器。
这种解决方案事实上是应用服务器的状态分离，分为无状态的应用服务器和有状态的session服务器，然后针对这两种服务器的不同特性分别设计架构。
对于有状态的session服务器，一种比较简单的方法是利用分布式缓存（memcached), 数据库等。在这些产品的基础上进行包装，使其符合session的存储和访问要求。
如果业务场景对session管理有比较高的要求，比如利用session服务基层单点登录（sso),用户服务器等功能，需要开发专门的session服务管理平台。

## 数据库
[mysql中key 、primary key 、unique key 与index区别](http://blog.csdn.net/nanamasuda/article/details/52543177)

## nginx redis
[redis,nginx相关面试](http://blog.csdn.net/qq_29108585/article/details/67074435)

[nginx面试要点--持续更新中](http://blog.csdn.net/watson2016/article/details/77938678)

[Nginx和Apache有什么区别](https://www.cnblogs.com/wt645631686/p/7572981.html)

[nginx 使用过程中一些基础性问题总结](https://www.cnblogs.com/qiuyan/p/4186435.html)

[高性能高并发 面试](https://www.cnblogs.com/heartstage/p/3415584.html)

[Redis面试题及分布式集群](http://blog.csdn.net/yajlv/article/details/73467865)

[Redis的那些最常见面试问题](https://www.cnblogs.com/Survivalist/p/8119891.html)

[redis面试总结](https://www.cnblogs.com/jiahaoJAVA/p/6244278.html)

[缓存技术PK：选择Memcached还是Redis](http://blog.csdn.net/sosfnima/article/details/51993181)

## 分布式
map-reduce之所以有效是基于两个哲学（1）大而化小 和 （2） 异而化同。 这两个应对了大数据中的volume和variety挑战。 

ZooKeeper是一个分布式的，开放源码的分布式应用程序协调服务，是Google的Chubby一个开源的实现，是Hadoop和Hbase的重要组件。它是一个为分布式应用提供一致性服务的软件，提供的功能包括：配置维护、域名服务、分布式同步、组服务等。

zookeeper是一个为分布式应用提供一致性服务的软件，它内部是一个分层的文件系统目录树结构，规定统一个目录下只能有一个唯一文件名。

Zookeeper 和 Chubby .他俩都是分布式选举算法的封装，用来解决分布式下的数据一致性问题，c是paxos的完全实现，z少有偏差。锁的问题，c肯定会用起来方便一点，z也有相应的办法可以实现。c没有开源具体怎么不太清楚，z用的比较多。

YARN是开源项目Hadoop的一个资源管理系统，最初设计是为了解决Hadoop中MapReduce计算框架中的资源管理问题，但是现在它已经是一个更加通用的资源管理系统，可以把MapReduce计算框架作为一个应用程序运行在YARN系统之上，通过YARN来管理资源。

![xx](https://gss0.bdstatic.com/-4o3dSag_xI4khGkpoWK1HF6hhy/baike/c0%3Dbaike92%2C5%2C5%2C92%2C30/sign=f1e638059b2397ddc274905638ebd9d2/d53f8794a4c27d1e46c53a2611d5ad6edcc43874.jpg)

![xx](http://dubbo.io/images//dubbo-architecture.png)

dubbo是用来跨系统通信的，即使不用集群也可以。一个系统用作客户端，一个系统则充当服务端。服务端要把自己的接口定义提供给客户端，客户端将接口定义在spring中的bean。客户端可以直接使用这个bean，就好像这些接口的实现也是在自己代码里一样。客户端和服务端启动的时候都会把自己的机器IP注册到zookeeper上。客户端会把zk上的服务端ip拉到磁盘上，并记录哪些ip提供哪些服务（服务端启动的时候暴露给zk）。然后调用的时候客户端会根据ip调用服务端的服务，这时候即使zk挂掉也没关系。 `rpc+zookeeper`

假设某商城有一个商品库存剩10个，用户A想要买6个，用户B想要买5个，在理想状态下，用户A先买走了6了，库存减少6个还剩4个，此时用户B应该无法购买5个，给出数量不足的提示；而在真实情况下，用户A和B同时获取到商品剩10个，A买走6个，在A更新库存之前，B又买走了5个，此时B更新库存，商品还剩5个，这就是典型的电商“秒杀”活动。

分布式锁需要具备哪些条件

1. 获取锁和释放锁的性能要好

2. 判断是否获得锁必须是原子性的，否则可能导致多个请求都获取到锁

3. 网络中断或宕机无法释放锁时，锁必须被清除，不然会发生死锁

4. 可重入一个线程中可以多次获取同一把锁，比如一个线程在执行一个带锁的方法，该方法中又调用了另一个需要相同锁的方法，则该线程可以直接执行调用的方法，而无需重新获得锁；

5. 阻塞锁和非阻塞锁，阻塞锁即没有获取到锁，则继续等待获取锁；非阻塞锁即没有获取到锁后，不继续等待，直接返回锁失败。

什么是锁

1. 在单进程的系统中，当存在多个线程可以同时改变某个变量（可变共享变量）时，就需要对变量或代码块做同步，使其在修改这种变量时能够线性执行消除并发修改变量。

2. 而同步的本质是通过锁来实现的。为了实现多个线程在一个时刻同一个代码块只能有一个线程可执行，那么需要在某个地方做个标记，这个标记必须每个线程都能看到，当标记不存在时可以设置该标记，其余后续线程发现已经有标记了则等待拥有标记的线程结束同步代码块取消标记后再去尝试设置标记。这个标记可以理解为锁。

3. 不同地方实现锁的方式也不一样，只要能满足所有线程都能看得到标记即可。如java中synchronize是在对象头设置标记，Lock接口的实现类基本上都只是某一个volitile修饰的int型变量其保证灭个线程都能拥有对该int的可见性和原子修改，linux内核中也是利用互斥量或信号量等内存数据做标记。

4. 除了利用内存数据做锁其实任何互斥的都能做锁（只考虑互斥情况），如流水表中流水号与时间结合做幂等校验可以看作是一个不会释放的锁，或者使用某个文件是否存在作为锁等。只需要满足在对标记进行修改能保证原子性和内存可见性即可。

[分布式锁的几种实现方式](http://www.hollischuang.com/archives/1716)

[阿里面试_技术问题和经验总结](https://www.cnblogs.com/zhangshiwen/p/5788467.html)

[对于Zookeeper一些面试题自己的答案](https://www.toutiao.com/i6446291810334540301/)

[百度正式开源其RPC框架brpc](https://segmentfault.com/a/1190000011407840)

[小米和京东的4道关于Dubbo、Zookeeper等的面试题，并有答案分享](https://www.phpyuan.com/233408.html)

[年底啦，java后台面试题整理](https://www.jianshu.com/p/f5dee1306d0d)

[Dubbo分布式服务框架入门（附工程）](http://www.importnew.com/19732.html)

## 最小生成树
边有权值的代价最小的连通子图

`Kruskal算法` 加边法
![xx](http://img.blog.csdn.net/20160714144315409)

`Prim算法` 加点法
![xx](http://img.blog.csdn.net/20160714161107576)


## 其他
[腾讯七大事业群](http://blog.csdn.net/junbujianwpl/article/details/52832094)
