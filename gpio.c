// gpio.c - GPIO handler

#include <bbb.h>														    //bbbライブラリのヘッダ

//GPIOを有効にする関数
void gpio_expoert(int n){
	int fd;																        //ディスクリプタ
	char buf[16];														      //文字列操作用バッファ

	sprintf(buf, "%d", n);												//連番を文字列に変換

	//exportを開く
	fd = open("/sys/class/gpio/export", O_WRONLY);
	write(fd, buf, strlen(buf));									//連番を書き込む
	close(fd);
}

//GPIOを無効にする関数
void gpio_unexpoert(int n){
	int fd;																        //ディスクリプタ
	char buf[16];														      //文字列操作用バッファ

	sprintf(buf, "%d", n);												//連番を文字列に変換

	//unexportを開く
	fd = open("/sys/class/gpio/export", O_WRONLY);
	write(fd, buf, strlen(buf));									//連番を書き込む
	close(fd);
}

//GPIOの制御用ファイルを開く関数
int gpio_open(int n, char *file, int flag){
	int fd;																        //ディスクリプタ
	char buf[40];														      //文字列操作用バッファ

	//パスを作成
	sprintf(buf, "/sys/class/gpio/gpio%d/%s", n, file);

	fd = open(buf, flag);												  //ファイルを開く
	return fd;															      //ディスクリプタを持ち帰る
}

