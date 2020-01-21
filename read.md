先set channel 
然后再loop

loop 中  while  {设置基本数据后  调用poller 的poll ,等poll返回 遍历activeChannellist，对每个元素进行handleEvent}

loop要监听哪些fd，通过新生成channel,然后ennable，然后update（即加入用户关注的fd）





poller被唤醒后
会将返回的numEvents和成员变量activeChannelList作为参数调用fillActiveChannels
在  fillActiveChannels 中  将识别的channel(识别之后会对channel重新设置属性)推入  activeChannelList

然后activeChannelList对每个channel调用handleEvent，触发相应回调

继续poll


	  --loop 有产生默认的fd, channel没有产生fd
	  ---server listen  产生第一个fd
	  --有新的连接进来，产生fd
	  --epoll对所有产生的fd进行监听
	  --所有有server产生的fd在http 的析构函数 close fd
	  
	  
	  
	  如果不用loop 和channel
	  直接用server http 和 epoll fd ,有何差别
	  假设现在有一个listenfd,如果新连接到来，是如何通知listenfd，是写数据到listenfd的缓冲区吗


eventLoop自己有一个channel 对象，每一个新的fd也应该有一个fd对象

fd---loop--poller--唤醒--loop--channel--channel的handleEvent--call回调

