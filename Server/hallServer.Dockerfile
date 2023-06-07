FROM ubuntu:latest

ENV TZ=Europe/Moscow
# author = "Parinova"
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update
RUN apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools -y
RUN apt-get install build-essential -y

EXPOSE 33333

WORKDIR /root/
RUN mkdir Parinova_221_352
WORKDIR /root/Parinova_221_352/
COPY * /root/Parinova_221_352/


RUN qmake echoServer.pro
RUN make 

ENTRYPOINT [ "./echoServer" ]

