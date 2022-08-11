#include <stdlib.h>
#include <memory.h>
#include "FIFO.h"


void newFIFO(FIFO *fifo, int len, int size)
{
  if (fifo->init) return;

  fifo->init = 1;
  fifo->nd   = 0;
  fifo->ne   = 0;
  fifo->cnt  = 0;
  fifo->sz   = size;
  fifo->len  = len;

  fifo->_ = malloc(len * size);
}

void delFIFO(FIFO *fifo)
{
  if (!fifo->_) return;

  fifo->init = 0;
  free(fifo->_);
}

int enqFIFO(FIFO *fifo, void *src)
{
  if (!fifo->init)            return -1;
  if (fifo->cnt >= fifo->len) return -1;

  memcpy(fifo->_ + fifo->ne*fifo->sz, src, fifo->sz);

  fifo->ne = ++(fifo->ne) % fifo->len;
  fifo->cnt++;

  return 0;
}

void *deqFIFO(FIFO *fifo)
{
  int i = fifo->nd;

  if (!fifo->init)    return -1;
  if (fifo->cnt == 0) return -1;

  fifo->nd = ++(fifo->nd) % fifo->len;
  fifo->cnt--;

  return (fifo->_ + i*fifo->sz);
}

void *seeFIFO(FIFO *fifo)
{
  if (!fifo->init)    return -1;
  if (fifo->cnt == 0) return -1;

  return (fifo->_ + fifo->nd*fifo->sz);
}

