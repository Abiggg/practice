#include <unistd.h>
#include <string.h>

int main()
{
  char keyboard[20] = {0};
  read(0, keyboard, 10);  //从标准输入（键盘）读取输入
  write(1, keyboard, strlen(keyboard)); //写入到屏幕中
  return 0;
}
