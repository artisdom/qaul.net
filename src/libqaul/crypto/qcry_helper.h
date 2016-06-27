/*
 * qaul.net is free software
 * licensed under GPL (version 3)
 */

#ifndef QAUL_QCRY_HELPER_H
#define QAUL_QCRY_HELPER_H

/***************** QCRY ERROR CODES *****************/

#define QCRY_STATUS_OK                  0
#define QCRY_STATUS_ERROR               1
#define QCRY_STATUS_FATAL               2

#define QCRY_STATUS_NOT_IMPLEMENTED     3

#define QCRY_STATUS_KEYGEN_FAILED       4
#define QCRY_STATUS_BFR_TOO_SMALL       10
#define QCRY_STATUS_INVALID_PARAMS      12

#define QCRY_STATUS_SEED_FAILED         14
#define QCRY_STATUS_CTX_INVALID         16
#define QCRY_STATUS_INVALID_TARGET      18
#define QCRY_STATUS_INVALID_KEYS        19

#define QCRY_STATUS_INVALID_KEYS        21
#define QCRY_STATUS_MALLOC_FAIL         22
#define QCRY_STATUS_KEY_BUSY            24

/***************** QCRY ERROR CODES *****************/

/* Flags used by the key generators */
#define QCRY_KEYS_AES             100
#define QCRY_KEYS_ECC             120
#define QCRY_KEYS_RSA             140
#define QCRY_KEYS_PREST_ON        180
#define QCRY_KEYS_PREST_OFF       230
#define QCRY_KEYS_QUIET_ON        350
#define QCRY_KEYS_QUIET_OFF       370
#define QCRY_KEYS_PERM_ON         410
#define QCRY_KEYS_PERM_OFF        415
#define QCRY_CIPH_CBC             425

/* Generic helper macros for all crypto code */

#define MAGICK_NO   3
#define MIN_BFR_S   4
#define MAX_TIMEOUT 500
#define TIME_SLEEP  50

/**
 * This macro checks if a buffer is full and should be increased in size.
 * Additionally it checks if a buffer is WAY too big for it's occupancy and
 * shrinks it. This macro should get used whenever things are
 * stored or removed from list buffers
 */
#define CHECK_BUFFER(type, bfr, max_s, curr_s) \
    { if(curr_s >= max_s) { \
        max_s *= 2; type *tmp = calloc(sizeof(type), max_s); \
        if(!tmp) return QCRY_STATUS_MALLOC_FAIL; \
        memcpy(tmp, bfr, sizeof(type) * curr_s); \
        free(bfr); \
        bfr = tmp; \
    } else if(curr_s * 3<= max_s) { max_s /= 2 ; \
    if(max_s < MIN_BFR_S) max_s = MIN_BFR_S; \
        type *tmp = calloc(sizeof(type), max_s); \
        if(!tmp) return QCRY_STATUS_MALLOC_FAIL; \
        memcpy(tmp, bfr, \
        sizeof(type) * curr_s); \
        free(bfr); \
        bfr = tmp; } \
    }

/**
 * create @a string from @a hash
 *
 * @retval 1 on success
 * @retval 0 on error
 */
int QCry_HashToString(unsigned char *hash, char *string);

/**
 * reconverts a hash string @a string to the @a hash
 *
 * @retval 1 on success
 * @retval 0 on error
 */
int QCry_StringToHash(char *string, unsigned char *hash);



#endif //QAUL_QCRY_HELPER_H
