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

/* Describes an input to a litecoin transaction */
struct tx_input {

    /* The hash of the previous transaction output */
    uint8_t prev_hash[HASH_LEN];

    /* The index of the specific output in the previous transaction */
    uint32_t index;

    /* The length of the signature script */
    uint64_t script_len;

    /* Computational script for confirming transaction authorization */
    uint8_t *script;

    /* 
     * Transaction version as defined by the sender. Intended for replacement
     * of transactions when information is updated before inclusion into a
     * block.
     */
    uint32_t sequence;

    struct tx_input *next;
};

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
    
struct block_header_hash {
	/* Block version info based on software version that created this block */
    uint32_t version;

    /* Hash value of the previous block this block references */
    uint8_t prev_block[HASH_LEN];

    /* 
     * Reference to a Merkle tree collection (hash of all transactions related
     * to this block) 
     */
    uint8_t merkle_root[HASH_LEN];

    /* Unix timestamp (32-bit) for when this block was created */
    uint32_t time;

    /* Calculated difficulty target being used for this block */
    uint32_t bits;

    /* 
     * Nonce used to generate this block to allow variations of the header and
     * compute different hashes
     */
    uint32_t nonce;    
};
struct BolckHeader {
	uint32_t blk_cnt;
	uint8_t *fph;
	uint32_t file_offset;
	uint8_t prev_block_hash[HASH_LEN];
};

#endif
