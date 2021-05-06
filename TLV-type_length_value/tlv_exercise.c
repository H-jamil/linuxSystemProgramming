/**
 * @Author: jamil
 * @Date:   2021-05-05T11:08:02-05:00
 * @Last modified by:   jamil
 * @Last modified time: 2021-05-05T12:16:41-05:00
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define TLV_OVERHEAD_SIZE    2

/* Assignment :
 * Implement the below macros, and use them in function decode_tlv_buffer
 * to decode TLV buffer and its contents*/
 #define ITERATE_TLV_BEGIN(start_ptr, type, length, tlv_ptr, buffer_size)    \
     for (size_t offset = 0; offset + 2 < buffer_size; offset += length) { \
         type = start_ptr[offset++]; \
         length = start_ptr[offset++]; \
         tlv_ptr = &start_ptr[offset]; { \

 #define ITERATE_TLV_END(start_ptr, type, length, tlv_ptr, buffer_size)  \
     }}

#define NAME_TLV_CODE	    1  // >> String format , Unit Data length 32B
#define WEBSITE_TLV_CODE	2  // >> String format,  Unit Data length 64B
#define EMP_ID_TLV_CODE    	3  // >> Integer format, Unit Data length 8B
#define IP_ADDRESS_TLV_CODE 4 // >> unit data size 16B

static uint8_t
get_unit_data_size(uint8_t tlv_type )
{
    switch(tlv_type){
        case NAME_TLV_CODE:
            return 32;
        case WEBSITE_TLV_CODE:
            return 64;
        case EMP_ID_TLV_CODE:
            return 8;
        default:
            return 0;
    }
}

/*Implement the below function, print all TLVs in the buffer using MACRO definitions*/
void
decode_tlv_buffer(unsigned char *tlv_buffer,
                  uint32_t tlv_buffer_size){

    uint8_t tlv_type;
    uint8_t tlv_len;
    uint8_t *tlv_value;

    int units = 0, i = 0;

    ITERATE_TLV_BEGIN(tlv_buffer, tlv_type, tlv_len, tlv_value, tlv_buffer_size){

        units = tlv_len/get_unit_data_size(tlv_type);

        switch(tlv_type){
            case NAME_TLV_CODE:
            for( i = 0; i < units; i++){
                printf("TLV Type = %d, Name = %s\n", tlv_type,
                    tlv_value + (i * get_unit_data_size(tlv_type)));
            }
            break;
            case WEBSITE_TLV_CODE:
            for( i = 0; i < units; i++){
                printf("TLV Type = %d, Website Name = %s\n", tlv_type,
                    tlv_value + (i * get_unit_data_size(tlv_type)));
            }
            break;
            case EMP_ID_TLV_CODE:
            for( i = 0; i < units; i++){
                printf("TLV Type = %d, Emp ID = %lu\n", tlv_type,
                    *(uint64_t *)(tlv_value + (i * get_unit_data_size(tlv_type))));
            }
            break;
            case IP_ADDRESS_TLV_CODE:
            for ( i = 0; i < units; i++){
                printf("TLV Type = %d, IP = %s\n", tlv_type,
                    tlv_value + (i * get_unit_data_size(tlv_type)));
            }
            break;

            default:
                ;
        }
    } ITERATE_TLV_END(tlv_buffer, tlv_type, tlv_len, tlv_value, tlv_buffer_size);
}

/*
   +------------------------------------+
   |           tlv_type = 1             |
   +------------------------------------+
   |           tlv_len = 64             |
   +------------------------------------+
   |                                    |
   |          Jamil Hasib(32B)       |
   +------------------------------------+
   |                                    |
   |-         RosaMarie(32B)              |
   +------------------------------------+
   |           tlv_type = 2             |
   +------------------------------------+
   |           tlv_len = 128            |
   +------------------------------------+
   |                                    |
   |          www.siu.edu(64B)          |
   +------------------------------------+
   |                                    |
   |          www.bestbuy.com(64B)      |
   +------------------------------------+
   |          tlv_type = 3              |
   +------------------------------------+
   |          tlv_len = 24              |
   +------------------------------------+
   |                                    |
   |          52437(8B)                 |
   +------------------------------------+
   |                                    |
   |          52438(8B)                 |
   +------------------------------------+
   |                                    |
   |          52439(8B)                 |
   +------------------------------------+
   |          tlv_type = 4              |
   +------------------------------------+
   |          tlv_len = 64              |
   +------------------------------------+
   |                                    |
   |          122.1.1.1(16B)            |
   +------------------------------------+
   |                                    |
   |         122.1.1.2(16B)             |
   +------------------------------------+
   |                                    |
   |          122.1.1.3(16B)            |
   +------------------------------------+
   |                                    |
   |          122.1.1.4(16B)            |
   +------------------------------------+
*/

/* The below function prepares the tlv buffer in the format
 * as shown in above diagram*/
unsigned char *
prepare_tlv_buffer(uint32_t *total_buffer_size){

    /*Take 222B of TLV buffer*/
    /*Take 288B of TLV buffer*/
    //*total_buffer_size = 222;
    *total_buffer_size = 288;
    unsigned char *tlv_buffer = calloc(1, *total_buffer_size);
    unsigned char *temp = NULL;

    *tlv_buffer = NAME_TLV_CODE;
    *(tlv_buffer + 1) = 64;
    strncpy(tlv_buffer + TLV_OVERHEAD_SIZE, "Jamil Hasib", 32);
    strncpy(tlv_buffer + TLV_OVERHEAD_SIZE + 32, "RosaMarie", 32);

    temp = tlv_buffer + TLV_OVERHEAD_SIZE + (32 * 2);

    *temp = WEBSITE_TLV_CODE;
    *(temp + 1) = 128;
    strncpy(temp + TLV_OVERHEAD_SIZE, "www.siu.edu", 64);
    strncpy(temp + TLV_OVERHEAD_SIZE + 64, "www.bestbuy.com", 64);
    temp += TLV_OVERHEAD_SIZE + (64 * 2);
    *temp = EMP_ID_TLV_CODE;
    *(temp + 1) = 24;
    uint64_t *emp_id = (uint64_t *)(temp + TLV_OVERHEAD_SIZE);
    *emp_id = 52437;
    *(emp_id + 1) = 52438;
    *(emp_id + 2) = 52439;
    printf("%d\n", (emp_id + 2));
    temp+=TLV_OVERHEAD_SIZE+(8*3);
    printf("%d\n", temp);
    *temp = IP_ADDRESS_TLV_CODE;
    *(temp + 1) = 4 * 16;
    strncpy(temp + TLV_OVERHEAD_SIZE + 16 * 0, "122.1.1.1", 16);
    strncpy(temp + TLV_OVERHEAD_SIZE + 16 * 1, "122.1.1.2", 16);
    strncpy(temp + TLV_OVERHEAD_SIZE + 16 * 2, "122.1.1.3", 16);
    strncpy(temp + TLV_OVERHEAD_SIZE + 16 * 3, "122.1.1.4", 16);
    temp += TLV_OVERHEAD_SIZE + (16 * 4);

    return tlv_buffer;
}

int
main(int argc, char **argv){

    uint32_t total_buffer_size = 0;
    unsigned char *tlv_buffer = prepare_tlv_buffer(&total_buffer_size);
    if(tlv_buffer && total_buffer_size)
        decode_tlv_buffer(tlv_buffer, total_buffer_size);
    return 0;
}
