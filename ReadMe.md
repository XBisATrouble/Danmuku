### QT实现桌面弹幕
1. 需要QtWebsocket支持。
2. 本地需要搭建websocket环境，也可以利用服务器115.159.113.139:1997完成通信。
### TODO:
1. 客户端窗口设置一些弹幕属性
2. 关键词过滤
3. 实际应用中的客户端识别

### 前端js代码，需要jquery支持
```javascript
<script type="text/javascript">
  var exampleSocket = new WebSocket("ws://ip:socket");

  exampleSocket.onopen = function (event) {
    var msg = {
    mode:"init",
    flag:"student",
    room:"2410",
    student:"2015213865",
    date: Date.now()
    };
    // 将其作为 JSON 格式字符串发送。
    exampleSocket.send(JSON.stringify(msg));
  };

  exampleSocket.onmessage = function (event) {
    console.log(event.data);
  }

  function send(){
    var content=document.getElementById('content').value
    var msg = {
    mode:"message",
    room:"2410",
    student:"2015213865",
    date: Date.now(),
    content:content
    };
    // 将其作为 JSON 格式字符串发送。
    exampleSocket.send(JSON.stringify(msg));
  }
</script>
```

### ws初始化握手json样式
```json
{
    "mode": "init",
    "flag": "student",
    "room": "2410",
    "student": "2015213865",
    "data": "2017年4月20日17:42:18"
}
```
>|参数|参数意义|
>|:---|:---|
>|mode|varchar，访问的类型，分为message（发送消息），init（握手初始化）|
>|flag|varchar，区分来自客户端还是学生网页客户端的请求，学生网页客户端为student|
>|room|varchar，房间号，由课表获得|
>|student|varchar，学生学号|
>|data|varchar，系统时间|


### 发送消息json样式
```json
{
    "mode": "message",
    "room": "2410",
    "student": "2015213865",
    "data": "2017年4月20日17:42:18",
    "content": "123"
}
```
>|参数|参数意义|
>|:---|:---|
>|mode|varchar，访问的类型，分为message（发送消息），init（握手初始化）|
>|room|varchar，房间号，由课表获得|
>|student|varchar，学生学号|
>|data|varchar，系统时间|
>|content|发送内容|

