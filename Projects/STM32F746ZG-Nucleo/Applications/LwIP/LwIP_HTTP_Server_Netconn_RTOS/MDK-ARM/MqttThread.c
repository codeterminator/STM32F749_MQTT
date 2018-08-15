#include "MQTTPacket.h"
#include "lwip/opt.h"
#include "lwip/arch.h"
#include "lwip/api.h"
#include "lwip/apps/fs.h"

#include <stdlib.h>
#include <string.h>

struct netconn* conn;
struct netbuf*  databuf;
ip_addr_t ip_addr;
int toStop = 0;

int getdata(unsigned char *buf, int count)
{
	struct netbuf *inbuf;
	return (int)netconn_recv(conn, &inbuf);
}

void  Dns_parse(void)
{
	struct ip_addr_t *ipaddr_DNS;
	const char hostname[] = "aliyun.iot.com";
	IP_ADDR4(&ip_addr,192,168,100,84);
}

void MqttThread(void)
{
	MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
	int rc = 0;
	unsigned char buf[200];
	int buflen = sizeof(buf);
	int msgid = 1;
	MQTTString topicString = MQTTString_initializer;
	int req_qos = 0;
	char* payload = "mypayload";
	int payloadlen = strlen(payload);
	int len = 0;
	
	data.clientID.cstring = "SendReceive test MQTT";
	data.keepAliveInterval = 20;
	data.cleansession = 1;
	struct netbuf *netbuf = NULL;
	
	conn = netconn_new(NETCONN_TCP);
	
	netconn_connect(conn, &ip_addr, 1883);

	//µÈ´ýÁ¬½Ó
	
	if (MQTTPacket_read(buf, buflen, getdata) == CONNACK)
	{
		unsigned char  sessionPresent,connack_rc;
		if (MQTTDeserialize_connack(&sessionPresent, &connack_rc, buf, buflen) != 1 || connack_rc != 0)
		{
			printf("unable to connect, reutnr code %d\n", connack_rc);
			goto exit;
		}
	}
	else 
		goto exit;
	topicString.cstring = "subtopic";
	len = MQTTSerialize_subscribe(buf, buflen, 0, msgid, 1, &topicString, &req_qos);
	
	rc = netconn_send(conn, netbuf);
	
	if (MQTTPacket_read(buf, buflen, getdata) == SUBACK)
	{
		
	}
	else
		goto exit;
	
	  topicString.cstring = "substopic";
    len = MQTTSerialize_subscribe(buf, buflen, 0, msgid, 1, &topicString, &req_qos);

    rc = netconn_send(conn, netbuf);
	 if (MQTTPacket_read(buf, buflen, getdata) == SUBACK)    /* wait for suback */
    {
        unsigned short submsgid;
        int subcount;
        int granted_qos;

        rc = MQTTDeserialize_suback(&submsgid, 1, &subcount, &granted_qos, buf, buflen);
        if (granted_qos != 0)
        {
            printf("granted qos != 0, %d\n", granted_qos);
            goto exit;
        }
    }
		else
			goto exit;
		topicString.cstring = "pubtopic";
		while(!toStop)
		{
			if (MQTTPacket_read(buf, buflen, getdata) == PUBLISH)
			{
				unsigned char dup;
				int qos;
				unsigned char retained;
				unsigned short msgid;
				int payloadlen_in;
        unsigned char* payload_in;
        int rc;
        MQTTString receivedTopic;
				
				rc = MQTTDeserialize_publish(&dup, &qos, &retained, &msgid, &receivedTopic,
                    &payload_in, &payloadlen_in, buf, buflen);
				printf("publishing reading\n");
				len = MQTTSerialize_publish(buf, buflen, 0, 0, 0, 0, topicString, (unsigned char*)payload, payloadlen);
			}
			netconn_send(conn, netbuf);
		}
	exit:
	  netconn_disconnect(conn);
	
}