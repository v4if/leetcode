
## 内存泄漏如何检测，如何解决
[C++内存泄漏的几种情况](http://www.cnblogs.com/SeekHit/p/6549940.html)

[C/C++内存泄漏及检测](https://www.cnblogs.com/skynet/archive/2011/02/20/1959162.html)

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
[shell脚本抽取制定字符串、grep+awk+cut+sed](http://blog.csdn.net/z
