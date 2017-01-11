//gpio_export-GPIOを有効にする
//引数-n:連番
void gpio_export(int n);

//gpio_unexport-GPIOを無効にする
//引数-n:連番
void gpio_unexport(int n);

//gpio_open-GPIOの制御用ファイルを開く
//引数-n:連番、file:ファイル名、flag:次行に示すフラグ
//フラグ-O_RDONLY:読み出し、O_WRONLY:書き込み、O_RDWR:読み書き
//戻値-ディスクリプタ、開けなかったら負の値
int gpio_open(int n, char *file, int flag);

