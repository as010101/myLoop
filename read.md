先set channel 
然后再loop

loop 中  while  {设置基本数据后  调用poller 的poll ,等poll返回 遍历activeChannellist，对每个元素进行handleEvent}

loop要监听哪些fd，通过新生成channel,然后ennable，然后update
