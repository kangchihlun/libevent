/*/*******************************************************************************
**                                                                            **
**                     Jiedi(China nanjing)Ltd.                               **
**	               创建：丁宋涛 夏曹俊，此代码可用作为学习参考                **
*******************************************************************************/

/*****************************FILE INFOMATION***********************************
**
** Project       : Libevent C＋＋高并发网络编程
** Contact       : xiacaojun@qq.com
**  博客   : http://blog.csdn.net/jiedichina
**	视频课程 : 网易云课堂	http://study.163.com/u/xiacaojun		
			   腾讯课堂		https://jiedi.ke.qq.com/				
			   csdn学院		http://edu.csdn.net/lecturer/lecturer_detail?lecturer_id=961	
**             51cto学院	http://edu.51cto.com/lecturer/index/user_id-12016059.html	
** 			   老夏课堂		http://www.laoxiaketang.com 
**                 
**  Libevent C＋＋高并发网络编程 课程群 ：1003847950 加入群下载代码和交流
**   微信公众号  : jiedi2007
**		头条号	 : 夏曹俊
**
*****************************************************************************
//！！！！！！！！！ Libevent C＋＋高并发网络编程 课程  QQ群：1003847950 下载代码和交流*/
/*
 * Copyright (c) 2007-2012 Niels Provos and Nick Mathewson
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef MM_INTERNAL_H_INCLUDED_
#define MM_INTERNAL_H_INCLUDED_

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef EVENT__DISABLE_MM_REPLACEMENT
/* Internal use only: Memory allocation functions. We give them nice short
 * mm_names for our own use, but make sure that the symbols have longer names
 * so they don't conflict with other libraries (like, say, libmm). */

/** Allocate uninitialized memory.
 *
 * @return On success, return a pointer to sz newly allocated bytes.
 *     On failure, set errno to ENOMEM and return NULL.
 *     If the argument sz is 0, simply return NULL.
 */
EVENT2_EXPORT_SYMBOL
void *event_mm_malloc_(size_t sz);

/** Allocate memory initialized to zero.
 *
 * @return On success, return a pointer to (count * size) newly allocated
 *     bytes, initialized to zero.
 *     On failure, or if the product would result in an integer overflow,
 *     set errno to ENOMEM and return NULL.
 *     If either arguments are 0, simply return NULL.
 */
EVENT2_EXPORT_SYMBOL
void *event_mm_calloc_(size_t count, size_t size);

/** Duplicate a string.
 *
 * @return On success, return a pointer to a newly allocated duplicate
 *     of a string.
 *     Set errno to ENOMEM and return NULL if a memory allocation error
 *     occurs (or would occur) in the process.
 *     If the argument str is NULL, set errno to EINVAL and return NULL.
 */
EVENT2_EXPORT_SYMBOL
char *event_mm_strdup_(const char *str);

EVENT2_EXPORT_SYMBOL
void *event_mm_realloc_(void *p, size_t sz);
EVENT2_EXPORT_SYMBOL
void event_mm_free_(void *p);
#define mm_malloc(sz) event_mm_malloc_(sz)
#define mm_calloc(count, size) event_mm_calloc_((count), (size))
#define mm_strdup(s) event_mm_strdup_(s)
#define mm_realloc(p, sz) event_mm_realloc_((p), (sz))
#define mm_free(p) event_mm_free_(p)
#else
#define mm_malloc(sz) malloc(sz)
#define mm_calloc(n, sz) calloc((n), (sz))
#define mm_strdup(s) strdup(s)
#define mm_realloc(p, sz) realloc((p), (sz))
#define mm_free(p) free(p)
#endif

#ifdef __cplusplus
}
#endif

#endif