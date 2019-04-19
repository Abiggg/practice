#ifndef __PTHREAD_ID_H__
#define __PTHREAD_ID_H__


/*@打印当前线程的ID
 *@in 字符串
 *@out
 */
void printids(const char *s);

/*@打印当前线程的ID
 *@in 字符串
 *@out
 */
void* thr_fn(void *arg);

#endif
