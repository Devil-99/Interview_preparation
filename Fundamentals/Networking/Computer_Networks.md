# **OSI Model :-**
1. **Physical Layer -** This layer is responsible for actual physical connection.

    - Bit synchronisation
    - Bit rate control
    - Network Topologies (Bus, Start etc.)
    - Transmission modes (Simplex, duplex).
    -  ***Device - Hub, Repeater, Modem, and Cables.***

2.  **Data Link Layer :-** Responsible for node-to-node message transfer with Flow Control and Error Control.

    - Physical / MAC Addressing
    - Flow Control
    - Error Control
    - Access Control
    - Data Link layer is handled by the NIC (Network Interface Card).
    - ***Device - Switch & Bridge***

3. **Network Layer :-** Responsible for Host-to-Host connection on different location.

    - Logical / IP Addressing.
    - Routing.
    - ***Device - routers***.

4. **Transport Layer :-** Responsible for end-to-end connection.

    - Segmentation of message.
    - Service point addressing / Port Addressing.
    - Transport layer is operated by the Operating System. It is a part of the OS and communicates with the Application Layer by making system calls. 
    - ***Device - Firewall.***
    - **Heart of the OSI model**

5. **Application Layer :-**

    1. **Session Layer :-** Responsible for the establishment of connection, maintenance of sessions, authentication and security.  
    ***Device - Gateway***

    2.  **Presentation Layer :-** Responsible for Data Encryption.

    3. **Application Layer :-** The actual application (GUI) like messenger, whatsapp.

#

## **1. Mac Address vs IP Address !**

    - A MAC address is a one-of-a-kind hardware identification number assigned to a NIC (Network Interface Controller/Card), whereas an IP address is a number that helps you identify a network connection.
    - The manufacturer of the hardware interface assigns the MAC address, but the network administrator or Internet Service Provider assigns the IP address (ISP).
    - The Mac address identifies the device, while the IP address indicates how it connects to the network.
    - IP addresses, on the other hand, can be used for broadcasting or multicasting, whereas MAC addresses can be only used for broadcasting.
    - The Data-Link layer of the OSI or TCP/IP reference model implements the MAC address. On the TCP/IP or OSI model, the IP address is implemented in the Network layer.

## **2. HTTP vs HTTPS**

    **HyperText Transfer Protocol (HTTP)** is a protocol using which hypertext is transferred over the Web. The data (i.e. hypertext) exchanged using http isn’t as secure. It goes as plain text i.e. anyone between the browser and server can read it relatively easy if one intercepts this exchange of data.

    That’s why **https** was introduced so that a secure session is setup first between Server and Browser. In fact, cryptographic protocols such as SSL and/or TLS turn http into https i.e. https = http + cryptographic protocols.

    http uses default port 80 while https uses default port 443.

    But it should be noted that this security in https is achieved at the cost of processing time because Web Server and Web Browser needs to exchange encryption keys using Certificates before actual data can be transferred. Basically, setting up of a secure session is done before the actual hypertext exchange between server and browser.

## **3. SSL and TLS**

    SSL - Secure Socket Layer
    TLS - Transport Layer Security

## **4. Proxy and Reverse Proxy**

[Link](https://www.cloudflare.com/en-gb/learning/cdn/glossary/reverse-proxy/)

**Forward Proxy** - Sits in front of client machine and communicates with web servers on behalf of those clients as a middleman.
- Browsing Restrictions
- Protect client's identity online.

**Reverse Proxy** - Sits in front of web servers, intecepting request from clients.
- Load Balancing
- Protection from attacks
- Caching

## **5. Load Balancer**

A **Load balancer** acts as the “traffic cop” sitting in front of your servers and routing client requests across all servers capable of fulfilling those requests in a manner that maximizes speed and capacity utilization and ensures that no one server is overworked, which could degrade performance.

If a single server goes down, the load balancer redirects traffic to the remaining online servers. When a new server is added to the server group, the load balancer automatically starts to send requests to it.

## **6. Browser Cache**

Every time a user loads a webpage, their browser has to download quite a lot of data in order to display that webpage. To **shorten page load times**, browsers stores most of the content that appears on the webpage, saving a copy of the webpage's content on the device’s hard drive.  
This way, the next time the user loads the page, most of the content is already stored locally and the page will load much more quickly.

- Browsers store these files until their time to live (TTL) expires or until the hard drive cache is full.
- Users can also clear their browser cache if desired.

**CDN Caching -** A CDN(content delivery network) caches content (such as images, videos, or webpages) in proxy servers that are located closer to end users than origin servers. Because the servers are closer to the user making the request, a CDN is able to deliver content more quickly.

## **7. Latency, Bandwidth, Throughput**

**Bandwidth -** Bandwidth is the name given to the number of packets that can be transferred throughout the network.

**Latency -** Latency indicates how long it takes for packets to reach their destination.

**Throughput -** Throughput is the term given to the number of packets that are processed within a specific period of time.

## **8. VPN**

Virtual Private Network is a protected network connection on a public network.  
It hides your IP address by letting the network redirect it through a specially configured remote server run by a VPN host.

This means your Internet Service Provider (ISP) and other third parties cannot see which websites you visit or what data you send and receive online. 

## **9. Transmission Media**

There are 2 types of Media-
1. Guided media - wired
2. Unguided - wireless

**Guided Media is of 3types mainly** -
1. Twisted pair cable - This is of 2 types  
    - unshielded - 2 insulated copper wire twisted around each other. Ex- telephone wire, LAN cable
    - Shielded - er 1ta extra copper shield thake external interference gulok atkanor jnno. Ex- fast-data-rate ethernet channel, voice and data channles of telephone line. Bises kore thandar des e extra protection er jnno

2. Coaxial cable - 1 gada insulator thake.. tar vetore main copper wire ta thake.. Ex- Cable tv connection gulo

3. Optic fiber cable - High speed internet er jnno.. AKhn jeta jio fiber e use kor6e

**Unguided media is of 3 types**  
1. Radio waves - FM radio, cordless phones
2. Microwaves - Mobile phones, TV distribution
3. Infrared - TV remote, wireless mouse.. (IR blaster jeta)