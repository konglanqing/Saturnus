/*  libevent_socket_server.c  */

//socket
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <stdio.h>
#include <string.h>

//libevent
#include <event.h>
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <event2/thread.h>

void listener_cb (struct evconnlistener *listener,evutil_socket_t fd,struct sockaddr*sock,int socklen,void *arg);

void socket_read_cb(struct bufferevent*bev,void *arg);

void socket_event_cb(struct bufferevent*bev,short events,void *arg);

int main (){


}


void listener_cb(struct evconnlistener*listener,evutil_socket_t fd,struct sockaddr*sock,int socklen,void *arg){
	
	printf("accept a client %d\n",fd);
	struct event_base*base = (struct event_base*)arg;
	//为此客户端分配一个buferevent
	struct bufferevnet *bev = bufferevent_socket_new(base,fd,BEV_OPT)
	bufferevent_setcb(bev,socket_read_cb,NULL,socket_event_cb,NULL);
	bufferevent_enable(bev,EV_READ | EV_PERAIST);

}


void socket_read_cb (struct bufferevent *bev,void *arg){

	char msg[4096];
	size_t len = bufferevent_read(bev, msg,sizeof(msg)-1);
	msg[len] = '\0';
	printf("server read the data %s \n ",msg);
	char reply[] = "I has read your data";
	bufferevent_write(bev,reply,strlen(reply));
}

void socket_event_cb(struct bufferevent*bev,short events,void *arg){

	if(event & BEV_EVENT_EOF){
	    printf("connection closed \n");
	}
	else if (event & BEV_EVENT_ERROR){
	    printf("other error\n");
	}
	//自动关闭套接字和释放读写缓冲区
	bufferevent_free(bev);
}


