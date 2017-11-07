#ifndef FORMAT_H_
#define FORMAT_H_

#include <stdint.h>

#define MAGIC_MAIN      0xDBB6C0FB
#define MAGIC_TESTNET   0xDCB7C1FC


enum magic_net {
    MAGIC_NET_NONE,
    MAGIC_NET_MAIN,
    MAGIC_NET_TESTNET
};

#define CMD_LEN         12
#define MAGIC_LEN       4
#define BLKSZ_LEN       4
#define VERSION_LEN     4
#define HASH_LEN        32
#define TIME_LEN        4
#define DIFFICULTY_LEN  4
#define NONCE_LEN       4
#define INDEX_LEN       4
#define VALUE_LEN       8
#define SEQUENCE_LEN    4
#define LOCKTIME_LEN    4
/* Format for a block in a litecoin blockchain */
struct block {

    /* Magic number */
    uint32_t magic;

    /* Length of the entire block */
    uint32_t size;
    
	struct block_header_hash blk_hash;
    /* 
     * Number of transaction entries
     */
    uint64_t tx_cnt;

    /* Transactions */
    struct tx *tx_list;

};
    

#endif
