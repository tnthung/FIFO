

typedef struct FIFO
{
  void *_;

  unsigned int ne;    // next enq
  unsigned int nd;    // next deq
  unsigned int sz;    // size of each element
  unsigned int len;   // length of FIFO
  unsigned int cnt;   // count of items in FIFO
  unsigned int init;  // if FIFO initialized

} FIFO;


void newFIFO(FIFO *fifo, int len, int size);
void delFIFO(FIFO *fifo);

int   enqFIFO(FIFO *fifo, void *src); // push element into FIFO
void *deqFIFO(FIFO *fifo);            // pop element from FIFO
void *seeFIFO(FIFO *fifo);            // get element without removing

int FIFOleft (FIFO *fifo);           // get the number of free space
int FIFOcount(FIFO *fifo);           // get the number of elements in FIFO
