先set channel 
然后再loop

loop 中  while  {设置基本数据后  调用poller 的poll ,等poll返回 遍历activeChannellist，对每个元素进行handleEvent}

loop要监听哪些fd，通过新生成channel,然后ennable，然后update





poller被唤醒后
会将返回的numEvents和成员变量activeChannelList作为参数调用fillActiveChannels
在  fillActiveChannels 中  将识别的channel(识别之后会对channel重新设置属性)推入  activeChannelList

然后activeChannelList对每个channel调用handleEvent，触发相应回调

继续poll
