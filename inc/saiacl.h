/**
 * Copyright (c) 2014 Microsoft Open Technologies, Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License"); you may
 *    not use this file except in compliance with the License. You may obtain
 *    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 *    THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
 *    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 *    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
 *    FOR A PARTICULAR PURPOSE, MERCHANTABILITY OR NON-INFRINGEMENT.
 *
 *    See the Apache Version 2.0 License for specific language governing
 *    permissions and limitations under the License.
 *
 *    Microsoft would like to thank the following companies for their review and
 *    assistance with these files: Intel Corporation, Mellanox Technologies Ltd,
 *    Dell Products, L.P., Facebook, Inc., Marvell International Ltd.
 *
 * @file    saiacl.h
 *
 * @brief   This module defines SAI ACL interface
 */

#if !defined (__SAIACL_H_)
#define __SAIACL_H_

#include <saitypes.h>

/**
 * @defgroup SAIACL SAI - ACL specific API definitions
 *
 * @{
 */

/**
 * @brief ACL IP Type
 */
typedef enum _sai_acl_ip_type_t
{
    /** Don't care */
    SAI_ACL_IP_TYPE_ANY,

    /** IPv4 and IPv6 packets */
    SAI_ACL_IP_TYPE_IP,

    /** Non-IP packet */
    SAI_ACL_IP_TYPE_NON_IP,

    /** Any IPv4 packet */
    SAI_ACL_IP_TYPE_IPV4ANY,

    /** Anything but IPv4 packets */
    SAI_ACL_IP_TYPE_NON_IPV4,

    /** IPv6 packet */
    SAI_ACL_IP_TYPE_IPV6ANY,

    /** Anything but IPv6 packets */
    SAI_ACL_IP_TYPE_NON_IPV6,

    /** ARP/RARP */
    SAI_ACL_IP_TYPE_ARP,

    /** ARP Request */
    SAI_ACL_IP_TYPE_ARP_REQUEST,

    /** ARP Reply */
    SAI_ACL_IP_TYPE_ARP_REPLY

} sai_acl_ip_type_t;

/**
 * @brief ACL IP Fragment
 */
typedef enum _sai_acl_ip_frag_t
{
    /** Any Fragment of Fragmented Packet */
    SAI_ACL_IP_FRAG_ANY,

    /** Non-Fragmented Packet */
    SAI_ACL_IP_FRAG_NON_FRAG,

    /** Non-Fragmented or First Fragment */
    SAI_ACL_IP_FRAG_NON_FRAG_OR_HEAD,

    /** First Fragment of Fragmented Packet */
    SAI_ACL_IP_FRAG_HEAD,

    /** Not the First Fragment */
    SAI_ACL_IP_FRAG_NON_HEAD

} sai_acl_ip_frag_t;

/**
 * @brief DTEL flow operation
 *
 * @warning experimental
 */
typedef enum _sai_acl_dtel_flow_op_t
{
    /** No operation (experimental) */
    SAI_ACL_DTEL_FLOW_OP_NOP,

    /** In-band Network Telemetry (experimental) */
    SAI_ACL_DTEL_FLOW_OP_INT,

    /** In-band OAM (experimental) */
    SAI_ACL_DTEL_FLOW_OP_IOAM,

    /** Packet Postcard (experimental) */
    SAI_ACL_DTEL_FLOW_OP_POSTCARD,

} sai_acl_dtel_flow_op_t;

/**
 * @brief ACL Action Type
 */
typedef enum _sai_acl_action_type_t
{
    /** Set Redirect */
    SAI_ACL_ACTION_TYPE_REDIRECT,

    /** Set tunnel endpoint IP */
    SAI_ACL_ACTION_TYPE_ENDPOINT_IP,

    /** Redirect Packet to a list of destination which can be a port list */
    SAI_ACL_ACTION_TYPE_REDIRECT_LIST,

    /** Packet Action */
    SAI_ACL_ACTION_TYPE_PACKET_ACTION,

    /** Flood Packet on Vlan domain */
    SAI_ACL_ACTION_TYPE_FLOOD,

    /** Attach/detach counter id to the entry */
    SAI_ACL_ACTION_TYPE_COUNTER,

    /** Ingress Mirror */
    SAI_ACL_ACTION_TYPE_MIRROR_INGRESS,

    /** Egress Mirror */
    SAI_ACL_ACTION_TYPE_MIRROR_EGRESS,

    /** Associate with policer */
    SAI_ACL_ACTION_TYPE_SET_POLICER,

    /** Decrement TTL */
    SAI_ACL_ACTION_TYPE_DECREMENT_TTL,

    /** Set Class-of-Service */
    SAI_ACL_ACTION_TYPE_SET_TC,

    /** Set Packet Color */
    SAI_ACL_ACTION_TYPE_SET_PACKET_COLOR,

    /** Set Packet Inner Vlan Id */
    SAI_ACL_ACTION_TYPE_SET_INNER_VLAN_ID,

    /** Set Packet Inner Vlan Priority */
    SAI_ACL_ACTION_TYPE_SET_INNER_VLAN_PRI,

    /** Set Packet Outer Vlan Id */
    SAI_ACL_ACTION_TYPE_SET_OUTER_VLAN_ID,

    /** Set Packet Outer Vlan Priority */
    SAI_ACL_ACTION_TYPE_SET_OUTER_VLAN_PRI,

    /** Add Packet Vlan Id */
    SAI_ACL_ACTION_TYPE_ADD_VLAN_ID,

    /** Add Packet Vlan Priority */
    SAI_ACL_ACTION_TYPE_ADD_VLAN_PRI,

    /** Set Packet Src MAC Address */
    SAI_ACL_ACTION_TYPE_SET_SRC_MAC,

    /** Set Packet Dst MAC Address */
    SAI_ACL_ACTION_TYPE_SET_DST_MAC,

    /** Set Packet Src IPv4 Address */
    SAI_ACL_ACTION_TYPE_SET_SRC_IP,

    /** Set Packet Src IPv4 Address */
    SAI_ACL_ACTION_TYPE_SET_DST_IP,

    /** Set Packet Src IPv6 Address */
    SAI_ACL_ACTION_TYPE_SET_SRC_IPV6,

    /** Set Packet Src IPv6 Address */
    SAI_ACL_ACTION_TYPE_SET_DST_IPV6,

    /** Set Packet DSCP */
    SAI_ACL_ACTION_TYPE_SET_DSCP,

    /** Set Packet ECN */
    SAI_ACL_ACTION_TYPE_SET_ECN,

    /** Set Packet L4 Src Port */
    SAI_ACL_ACTION_TYPE_SET_L4_SRC_PORT,

    /** Set Packet L4 Src Port */
    SAI_ACL_ACTION_TYPE_SET_L4_DST_PORT,

    /** Set ingress packet sampling */
    SAI_ACL_ACTION_TYPE_INGRESS_SAMPLEPACKET_ENABLE,

    /** Set egress packet sampling */
    SAI_ACL_ACTION_TYPE_EGRESS_SAMPLEPACKET_ENABLE,

    /** Set metadata to carry forward to next ACL stage */
    SAI_ACL_ACTION_TYPE_SET_ACL_META_DATA,

    /** Egress block port list. To be deprecated */
    SAI_ACL_ACTION_TYPE_EGRESS_BLOCK_PORT_LIST,

    /** Set user defined trap id */
    SAI_ACL_ACTION_TYPE_SET_USER_TRAP_ID,

    /** Set Do Not Learn unknown source MAC */
    SAI_ACL_ACTION_TYPE_SET_DO_NOT_LEARN,

    /** Set DTEL flow operation (experimental) */
    SAI_ACL_ACTION_TYPE_ACL_DTEL_FLOW_OP,

    /** Set DTEL INT session (experimental) */
    SAI_ACL_ACTION_TYPE_DTEL_INT_SESSION,

    /** Enable DTEL drop report (experimental) */
    SAI_ACL_ACTION_TYPE_DTEL_DROP_REPORT_ENABLE,

    /** Enable DTEL tail drop reporting (experimental) */
    SAI_ACL_ACTION_TYPE_DTEL_TAIL_DROP_REPORT_ENABLE,

    /** Set DTEL flow sampling (experimental) */
    SAI_ACL_ACTION_TYPE_DTEL_FLOW_SAMPLE_PERCENT,

    /** Enable DTEL report for all packets without filtering (experimental) */
    SAI_ACL_ACTION_TYPE_DTEL_REPORT_ALL_PACKETS,

    /** Set NAT exception rule */
    SAI_ACL_ACTION_TYPE_NO_NAT,

    /** Enable insertion of INT metadata */
    SAI_ACL_ACTION_TYPE_INT_INSERT,

    /** Enable deletion of INT metadata */
    SAI_ACL_ACTION_TYPE_INT_DELETE,

    /** Enable reports of INT metadata */
    SAI_ACL_ACTION_TYPE_INT_REPORT_FLOW,

    /** Enable INT drop reports */
    SAI_ACL_ACTION_TYPE_INT_REPORT_DROPS,

    /** Enable INT tail drop reports */
    SAI_ACL_ACTION_TYPE_INT_REPORT_TAIL_DROPS,

    /** Bind a TAM INT object */
    SAI_ACL_ACTION_TYPE_TAM_INT_OBJECT,

    /** Set isolation group to prevent traffic to members of isolation group */
    SAI_ACL_ACTION_TYPE_SET_ISOLATION_GROUP,

    /** Bind a MACsec flow object */
    SAI_ACL_ACTION_TYPE_MACSEC_FLOW,

    /** Set custom LAG hash object ID */
    SAI_ACL_ACTION_TYPE_SET_LAG_HASH_ID,

    /** Set custom ECMP hash object ID */
    SAI_ACL_ACTION_TYPE_SET_ECMP_HASH_ID,

    /** Associate with virtual router */
    SAI_ACL_ACTION_TYPE_SET_VRF

} sai_acl_action_type_t;

/**
 * @brief Attribute data for SAI_ACL_TABLE_GROUP_ATTR_TYPE
 */
typedef enum _sai_acl_table_group_type_t
{
    /** SEQUENTIAL */
    SAI_ACL_TABLE_GROUP_TYPE_SEQUENTIAL,

    /** PARALLEL */
    SAI_ACL_TABLE_GROUP_TYPE_PARALLEL,

} sai_acl_table_group_type_t;

/**
 * @brief Attribute Id for acl_table_group
 */
typedef enum _sai_acl_table_group_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_ACL_TABLE_GROUP_ATTR_START,

    /**
     * @brief ACL stage
     *
     * @type sai_acl_stage_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_ACL_TABLE_GROUP_ATTR_ACL_STAGE = SAI_ACL_TABLE_GROUP_ATTR_START,

    /**
     * @brief List of ACL bind points where this group will be applied.
     *
     * ACL group bind point list - create only attribute required for ACL
     * groups to let the user specify his intention to allow further error
     * checks and optimizations based on a specific ASIC SAI implementation.
     * ACL members being added to this group SHOULD be a subset of the bind
     * point list that ACL group was created with.
     *
     * @type sai_s32_list_t sai_acl_bind_point_type_t
     * @flags CREATE_ONLY
     * @default empty
     */
    SAI_ACL_TABLE_GROUP_ATTR_ACL_BIND_POINT_TYPE_LIST,

    /**
     * @brief ACL table group type
     *
     * ACL table group type represents the way various ACL tables within this
     * ACL table group perform their lookups. There are two optional values:
     * Sequential - All the ACL tables are looked up in a sequential order,
     * which is based on the ACL table priorities and only one ACL entry is matched
     * with its corresponding ACL entry action applied. In case two ACL tables
     * have the same priority they are looked up on a first come basis.
     * Parallel - All the ACL tables within the ACL table groups are looked up
     * in parallel and non-conflicting actions are resolved and applied from
     * multiple matched ACL entries (each from different ACL tables of this group).
     *
     * @type sai_acl_table_group_type_t
     * @flags CREATE_ONLY
     * @default SAI_ACL_TABLE_GROUP_TYPE_SEQUENTIAL
     */
    SAI_ACL_TABLE_GROUP_ATTR_TYPE,

    /**
     * @brief ACL table group members associated with this group.
     *
     * @type sai_object_list_t
     * @flags READ_ONLY
     * @objects SAI_OBJECT_TYPE_ACL_TABLE_GROUP_MEMBER
     */
    SAI_ACL_TABLE_GROUP_ATTR_MEMBER_LIST,

    /**
     * @brief End of attributes
     */
    SAI_ACL_TABLE_GROUP_ATTR_END,

    /**
     * @brief Custom range base value start
     */
    SAI_ACL_TABLE_GROUP_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /**
     * @brief End of Custom range base
     */
    SAI_ACL_TABLE_GROUP_ATTR_CUSTOM_RANGE_END

} sai_acl_table_group_attr_t;

/**
 * @brief Attribute Id for acl_table_group_member
 */
typedef enum _sai_acl_table_group_member_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_ACL_TABLE_GROUP_MEMBER_ATTR_START,

    /**
     * @brief ACL table group id
     *
     * This attribute is required to associate or attach a member object (acl_table_id)
     * to a ACL table group id allocated during create ACL group API.
     *
     * User should always use the group id returned by SAI create_acl_group API,
     * to group the tables else Invalid attribute value error code will be returned.
     *
     * The ACL Table lookup could be done serially or in parallel. In both the
     * cases there could be a need to group multiple tables so that only single
     * ACL rule entry actions are performed in case of serial, or non-conflicting
     * actions are resolved in case of parallel.
     *
     * @type sai_object_id_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @objects SAI_OBJECT_TYPE_ACL_TABLE_GROUP
     */
    SAI_ACL_TABLE_GROUP_MEMBER_ATTR_ACL_TABLE_GROUP_ID = SAI_ACL_TABLE_GROUP_MEMBER_ATTR_START,

    /**
     * @brief ACL table id
     *
     * @type sai_object_id_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @objects SAI_OBJECT_TYPE_ACL_TABLE
     */
    SAI_ACL_TABLE_GROUP_MEMBER_ATTR_ACL_TABLE_ID,

    /**
     * @brief Priority
     *
     * Value must be in the range defined in
     * [SAI_SWITCH_ATTR_ACL_TABLE_MINIMUM_PRIORITY,
     * SAI_SWITCH_ATTR_ACL_TABLE_MAXIMUM_PRIORITY]
     *
     * This priority attribute is only valid for SEQUENTIAL type of ACL groups
     *
     * @type sai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_ACL_TABLE_GROUP_MEMBER_ATTR_PRIORITY,

    /**
     * @brief End of attributes
     */
    SAI_ACL_TABLE_GROUP_MEMBER_ATTR_END,

    /**
     * @brief Custom range base value start
     */
    SAI_ACL_TABLE_GROUP_MEMBER_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /**
     * @brief End of Custom range base
     */
    SAI_ACL_TABLE_GROUP_MEMBER_ATTR_CUSTOM_RANGE_END

} sai_acl_table_group_member_attr_t;

/**
 * @brief ACL User Defined Field Attribute ID Range
 */
#define SAI_ACL_USER_DEFINED_FIELD_ATTR_ID_RANGE 0xFF

/**
 * @brief Attribute Id for sai_acl_table
 *
 * @flags Contains flags
 */
typedef enum _sai_acl_table_attr_t
{
    /**
     * @brief Table attributes start
     */
    SAI_ACL_TABLE_ATTR_START,

    /**
     * @brief ACL stage
     *
     * @type sai_acl_stage_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_ACL_TABLE_ATTR_ACL_STAGE = SAI_ACL_TABLE_ATTR_START,

    /**
     * @brief List of ACL bind point where this ACL can be applied
     *
     * (Default = empty) - if the bind point is empty during create or
     * ACL Table that is previously bound is unbound, then it is expected that
     * there is no real hardware resource that is being utilized. In this case,
     * application is not expected to query for SAI_ACL_TABLE_ATTR_AVAILABLE_ACL_ENTRY
     * or SAI_ACL_TABLE_ATTR_AVAILABLE_ACL_COUNTER. If it is queried, the result is
     * undefined
     *
     * @type sai_s32_list_t sai_acl_bind_point_type_t
     * @flags CREATE_ONLY
     * @default empty
     */
    SAI_ACL_TABLE_ATTR_ACL_BIND_POINT_TYPE_LIST,

    /**
     * @brief Table size
     *
     * (Default = 0) - Grow dynamically till MAX ACL TCAM Size
     * By default, table can grow up to maximum ACL TCAM space.
     * Supported only during Table Create for now until NPU
     * supports Dynamic adjustment of Table size post Table creation
     *
     * The table size refers to the number of ACL entries. The number
     * of entries that gets allocated when we create a table with a
     * specific size would depend on the ACL CAM Arch of the NPU. Some
     * NPU supports different blocks, each may have same or different
     * size and what gets allocated can depend on the block size or other
     * factors. So internally what gets allocated when we do a table
     * create would be based on the NPU CAM Arch and size may be more
     * than what is requested. As an example the NPU may support blocks of
     * 128 entries. When a user creates a table of size 100, the actual
     * size that gets allocated is 128. Hence, it's recommended that the user
     * does a get_attribute(#SAI_ACL_TABLE_ATTR_SIZE) to query the actual
     * table size on table create so the user knows the ACL CAM space
     * allocated and able to do ACL CAM Carving accurately.
     *
     * @type sai_uint32_t
     * @flags CREATE_ONLY
     * @default 0
     * @isresourcetype true
     */
    SAI_ACL_TABLE_ATTR_SIZE,

    /**
     * @brief List of actions in sai_acl_action_type_t
     *
     * Based on the ACL capability per stage obtained from the switch
     * attributes #SAI_SWITCH_ATTR_ACL_STAGE_INGRESS and #SAI_SWITCH_ATTR_ACL_STAGE_EGRESS
     * application should pass the action list if its mandatory per stage.
     * Pass the action list if its mandatory per stage.
     * If its not mandatory application can either pass the action list
     * or ignore it.
     *
     * @type sai_s32_list_t sai_acl_action_type_t
     * @flags CREATE_ONLY
     * @default empty
     */
    SAI_ACL_TABLE_ATTR_ACL_ACTION_TYPE_LIST,

    /*
     * Match fields [bool]
     * Mandatory to pass at least one field during ACL Table creation.
     * Match fields cannot be changed after the table is created.
     */

    /**
     * @brief Start of Table Match Field
     */
    SAI_ACL_TABLE_ATTR_FIELD_START = 0x00001000,

    /**
     * @brief Src IPv6 Address
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_SRC_IPV6 = SAI_ACL_TABLE_ATTR_FIELD_START,

    /**
     * @brief Src IPv6 Address 127:96 32 bits
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_SRC_IPV6_WORD3,

    /**
     * @brief Src IPv6 Address 95:64 32 bits
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_SRC_IPV6_WORD2,

    /**
     * @brief Src IPv6 Address 63:32 32 bits
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_SRC_IPV6_WORD1,

    /**
     * @brief Src IPv6 Address 31:0 32 bits
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_SRC_IPV6_WORD0,

    /**
     * @brief Dst IPv6 Address
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_DST_IPV6,

    /**
     * @brief Dst IPv6 Address 127:96 32 bits
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_DST_IPV6_WORD3,

    /**
     * @brief Dst IPv6 Address 95:64 32 bits
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_DST_IPV6_WORD2,

    /**
     * @brief Dst IPv6 Address 63:32 32 bits
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_DST_IPV6_WORD1,

    /**
     * @brief Dst IPv6 Address 31:0 32 bits
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_DST_IPV6_WORD0,

    /**
     * @brief Inner Src IPv6 Address
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_INNER_SRC_IPV6,

    /**
     * @brief Inner Dst IPv6 Address
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_INNER_DST_IPV6,

    /**
     * @brief Src MAC Address
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_SRC_MAC,

    /**
     * @brief Dst MAC Address
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_DST_MAC,

    /**
     * @brief Src IPv4 Address
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_SRC_IP,

    /**
     * @brief Dst IPv4 Address
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_DST_IP,

    /**
     * @brief Inner Src IPv4 Address
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_INNER_SRC_IP,

    /**
     * @brief Inner Dst IPv4 Address
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_INNER_DST_IP,

    /**
     * @brief In-Ports
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_IN_PORTS,

    /**
     * @brief Out-Ports
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_OUT_PORTS,

    /**
     * @brief In-Port
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_IN_PORT,

    /**
     * @brief Out-Port
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_OUT_PORT,

    /**
     * @brief Source Port
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_SRC_PORT,

    /**
     * @brief Outer Vlan Id
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_OUTER_VLAN_ID,

    /**
     * @brief Outer Vlan Priority
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_OUTER_VLAN_PRI,

    /**
     * @brief Outer Vlan CFI
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_OUTER_VLAN_CFI,

    /**
     * @brief Inner Vlan Id
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_INNER_VLAN_ID,

    /**
     * @brief Inner Vlan Priority
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_INNER_VLAN_PRI,

    /**
     * @brief Inner Vlan CFI
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_INNER_VLAN_CFI,

    /**
     * @brief L4 Src Port
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_L4_SRC_PORT,

    /**
     * @brief L4 Dst Port
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_L4_DST_PORT,

    /**
     * @brief Inner L4 Src Port
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_INNER_L4_SRC_PORT,

    /**
     * @brief Inner L4 Dst Port
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_INNER_L4_DST_PORT,

    /**
     * @brief EtherType
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_ETHER_TYPE,

    /**
     * @brief Inner EtherType
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_INNER_ETHER_TYPE,

    /**
     * @brief IP Protocol
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_IP_PROTOCOL,

    /**
     * @brief Inner IP Protocol
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_INNER_IP_PROTOCOL,

    /**
     * @brief IP Identification
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_IP_IDENTIFICATION,

    /**
     * @brief IP DSCP
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_DSCP,

    /**
     * @brief IP ECN
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_ECN,

    /**
     * @brief IP TTL
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_TTL,

    /**
     * @brief IP TOS
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_TOS,

    /**
     * @brief IP Flags
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_IP_FLAGS,

    /**
     * @brief TCP Flags
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_TCP_FLAGS,

    /**
     * @brief IP Type
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_ACL_IP_TYPE,

    /**
     * @brief IP Frag
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_ACL_IP_FRAG,

    /**
     * @brief IPv6 Flow Label
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_IPV6_FLOW_LABEL,

    /**
     * @brief Class-of-Service (Traffic Class)
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_TC,

    /**
     * @brief ICMP Type
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_ICMP_TYPE,

    /**
     * @brief ICMP Code
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_ICMP_CODE,

    /**
     * @brief ICMP Type for IPv6
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_ICMPV6_TYPE,

    /**
     * @brief ICMP Code for IPv6
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_ICMPV6_CODE,

    /**
     * @brief Vlan Tags
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_PACKET_VLAN,

    /**
     * @brief Tunnel VNI
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_TUNNEL_VNI,

    /**
     * @brief Match on packet that has vlan tag
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_HAS_VLAN_TAG,

    /**
     * @brief SCI value in MACsec packet SecTAG
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_MACSEC_SCI,

    /**
     * @brief Label value for MPLS label on the top
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_MPLS_LABEL0_LABEL,

    /**
     * @brief TTL value for MPLS label on the top
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_MPLS_LABEL0_TTL,

    /**
     * @brief EXP value for MPLS label on the top
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_MPLS_LABEL0_EXP,

    /**
     * @brief BOS bit value for MPLS label on the top
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_MPLS_LABEL0_BOS,

    /**
     * @brief Label value for second MPLS label from the top
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_MPLS_LABEL1_LABEL,

    /**
     * @brief TTL value for second MPLS label from the top
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_MPLS_LABEL1_TTL,

    /**
     * @brief EXP value for second MPLS label from the top
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_MPLS_LABEL1_EXP,

    /**
     * @brief BOS bit value for second MPLS label from the top
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_MPLS_LABEL1_BOS,

    /**
     * @brief Label value for third MPLS label from the top
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_MPLS_LABEL2_LABEL,

    /**
     * @brief TTL value for third MPLS label from the top
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_MPLS_LABEL2_TTL,

    /**
     * @brief EXP value for third MPLS label from the top
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_MPLS_LABEL2_EXP,

    /**
     * @brief BOS bit value for third MPLS label from the top
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_MPLS_LABEL2_BOS,

    /**
     * @brief Label value for fourth MPLS label from the top
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_MPLS_LABEL3_LABEL,

    /**
     * @brief TTL value for fourth MPLS label from the top
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_MPLS_LABEL3_TTL,

    /**
     * @brief EXP value for fourth MPLS label from the top
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_MPLS_LABEL3_EXP,

    /**
     * @brief BOS bit value for fourth MPLS label from the top
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_MPLS_LABEL3_BOS,

    /**
     * @brief Label value for fifth MPLS label from the top
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_MPLS_LABEL4_LABEL,

    /**
     * @brief TTL value for fifth MPLS label from the top
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_MPLS_LABEL4_TTL,

    /**
     * @brief EXP value for fifth MPLS label from the top
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_MPLS_LABEL4_EXP,

    /**
     * @brief BOS bit value for fifth MPLS label from the top
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_MPLS_LABEL4_BOS,

    /* User Based metadata [bool] */

    /**
     * @brief FDB DST user meta data
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_FDB_DST_USER_META,

    /**
     * @brief ROUTE DST User Meta data
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_ROUTE_DST_USER_META,

    /**
     * @brief Neighbor DST User metadata
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_NEIGHBOR_DST_USER_META,

    /**
     * @brief Port User metadata
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_PORT_USER_META,

    /**
     * @brief Vlan User metadata
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_VLAN_USER_META,

    /**
     * @brief Metadata carried from previous ACL Stage
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_ACL_USER_META,

    /* NPU Based metadata [bool] */

    /**
     * @brief DST MAC address match in FDB
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_FDB_NPU_META_DST_HIT,

    /**
     * @brief DST IP address match in neighbor table
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_NEIGHBOR_NPU_META_DST_HIT,

    /**
     * @brief DST IP address match in Route table
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_ROUTE_NPU_META_DST_HIT,

    /**
     * @brief Base Transport Header opcode field
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_BTH_OPCODE,

    /**
     * @brief Ack_extented Transport Header syndrome field
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_AETH_SYNDROME,

    /**
     * @brief User Defined Field Groups
     * Length is derived from the UDF group OID
     *
     * @type sai_object_id_t
     * @flags CREATE_ONLY
     * @objects SAI_OBJECT_TYPE_UDF_GROUP
     * @allownull true
     * @default SAI_NULL_OBJECT_ID
     * @range SAI_ACL_USER_DEFINED_FIELD_ATTR_ID_RANGE
     */
    SAI_ACL_TABLE_ATTR_USER_DEFINED_FIELD_GROUP_MIN,

    /**
     * @brief User Defined Field Groups end
     * Length is derived from the UDF group OID
     *
     * @type sai_object_id_t
     * @flags CREATE_ONLY
     * @objects SAI_OBJECT_TYPE_UDF_GROUP
     * @allownull true
     * @default SAI_NULL_OBJECT_ID
     */
    SAI_ACL_TABLE_ATTR_USER_DEFINED_FIELD_GROUP_MAX = SAI_ACL_TABLE_ATTR_USER_DEFINED_FIELD_GROUP_MIN + SAI_ACL_USER_DEFINED_FIELD_ATTR_ID_RANGE,

    /**
     * @brief Range type defined
     *
     * @type sai_s32_list_t sai_acl_range_type_t
     * @flags CREATE_ONLY
     * @default empty
     */
    SAI_ACL_TABLE_ATTR_FIELD_ACL_RANGE_TYPE,

    /**
     * @brief IPv6 Next Header
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_IPV6_NEXT_HEADER,

    /**
     * @brief GRE key
     *
     * The key is dedicated for GRE packets.
     * The VNI key should not be used for matching on GRE packets or NVGRE packets.
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_GRE_KEY,

    /**
     * @brief TAM INT type
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_TAM_INT_TYPE,

    /**
     * @brief End of ACL Table Match Field
     */
    SAI_ACL_TABLE_ATTR_FIELD_END = SAI_ACL_TABLE_ATTR_FIELD_TAM_INT_TYPE,

    /**
     * @brief ACL table entries associated with this table.
     *
     * @type sai_object_list_t
     * @flags READ_ONLY
     * @objects SAI_OBJECT_TYPE_ACL_ENTRY
     */
    SAI_ACL_TABLE_ATTR_ENTRY_LIST = 0x00002000,

    /**
     * @brief Available ACL entries for this table
     *
     * @type sai_uint32_t
     * @flags READ_ONLY
     */
    SAI_ACL_TABLE_ATTR_AVAILABLE_ACL_ENTRY,

    /**
     * @brief Available ACL counters for this table
     *
     * @type sai_uint32_t
     * @flags READ_ONLY
     */
    SAI_ACL_TABLE_ATTR_AVAILABLE_ACL_COUNTER,

    /**
     * @brief End of ACL Table attributes
     */
    SAI_ACL_TABLE_ATTR_END,

    /**
     * @brief Custom range base value start
     */
    SAI_ACL_TABLE_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /**
     * @brief End of Custom range base
     */
    SAI_ACL_TABLE_ATTR_CUSTOM_RANGE_END

} sai_acl_table_attr_t;

/**
 * @brief Attribute Id for sai_acl_entry
 *
 * @flags Contains flags
 */
typedef enum _sai_acl_entry_attr_t
{
    /**
     * @brief Start of ACL Entry attributes
     */
    SAI_ACL_ENTRY_ATTR_START,

    /**
     * @brief SAI ACL table object id
     *
     * @type sai_object_id_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @objects SAI_OBJECT_TYPE_ACL_TABLE
     * @isresourcetype true
     */
    SAI_ACL_ENTRY_ATTR_TABLE_ID = SAI_ACL_ENTRY_ATTR_START,

    /**
     * @brief Priority
     *
     * Value must be in the range defined in
     * \[#SAI_SWITCH_ATTR_ACL_ENTRY_MINIMUM_PRIORITY,
     * #SAI_SWITCH_ATTR_ACL_ENTRY_MAXIMUM_PRIORITY\]
     * (default = #SAI_SWITCH_ATTR_ACL_ENTRY_MINIMUM_PRIORITY)
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_ACL_ENTRY_ATTR_PRIORITY,

    /**
     * @brief Admin state
     *
     * @type bool
     * @flags CREATE_AND_SET
     * @default true
     */
    SAI_ACL_ENTRY_ATTR_ADMIN_STATE,

    /*
     * Match fields [sai_acl_field_data_t]
     * - Mandatory to pass at least one field during ACL Rule creation.
     * - Unless noted specifically, both data and mask are required.
     * - When bit field is used, only those least significant bits are valid for
     * matching.
     */

    /**
     * @brief Start of Rule Match Fields
     */
    SAI_ACL_ENTRY_ATTR_FIELD_START = 0x00001000,

    /**
     * @brief Src IPv6 Address
     *
     * @type sai_acl_field_data_t sai_ip6_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_SRC_IPV6 = SAI_ACL_ENTRY_ATTR_FIELD_START,

    /**
     * @brief Src IPv6 Address 127:96 32 bits
     *
     * @type sai_acl_field_data_t sai_ip6_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_SRC_IPV6_WORD3,

    /**
     * @brief Src IPv6 Address 95:64 32 bits
     *
     * @type sai_acl_field_data_t sai_ip6_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_SRC_IPV6_WORD2,

    /**
     * @brief Src IPv6 Address 63:32 32 bits
     *
     * @type sai_acl_field_data_t sai_ip6_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_SRC_IPV6_WORD1,

    /**
     * @brief Src IPv6 Address 31:0 32 bits
     *
     * @type sai_acl_field_data_t sai_ip6_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_SRC_IPV6_WORD0,

    /**
     * @brief Dst IPv6 Address
     *
     * @type sai_acl_field_data_t sai_ip6_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_DST_IPV6,

    /**
     * @brief Dst IPv6 Address 127:96 32 bits
     *
     * @type sai_acl_field_data_t sai_ip6_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_DST_IPV6_WORD3,

    /**
     * @brief Dst IPv6 Address 95:64 32 bits
     *
     * @type sai_acl_field_data_t sai_ip6_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_DST_IPV6_WORD2,

    /**
     * @brief Dst IPv6 Address 63:32 32 bits
     *
     * @type sai_acl_field_data_t sai_ip6_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_DST_IPV6_WORD1,

    /**
     * @brief Dst IPv6 Address 31:0 32 bits
     *
     * @type sai_acl_field_data_t sai_ip6_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_DST_IPV6_WORD0,

    /**
     * @brief Inner Src IPv6 Address
     *
     * @type sai_acl_field_data_t sai_ip6_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_INNER_SRC_IPV6,

    /**
     * @brief Inner Dst IPv6 Address
     *
     * @type sai_acl_field_data_t sai_ip6_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_INNER_DST_IPV6,

    /**
     * @brief Src MAC Address
     *
     * @type sai_acl_field_data_t sai_mac_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_SRC_MAC,

    /**
     * @brief Dst MAC Address
     *
     * @type sai_acl_field_data_t sai_mac_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_DST_MAC,

    /**
     * @brief Src IPv4 Address
     *
     * @type sai_acl_field_data_t sai_ip4_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_SRC_IP,

    /**
     * @brief Dst IPv4 Address
     *
     * @type sai_acl_field_data_t sai_ip4_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_DST_IP,

    /**
     * @brief Inner Src IPv4 Address
     *
     * @type sai_acl_field_data_t sai_ip4_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_INNER_SRC_IP,

    /**
     * @brief Inner Dst IPv4 Address
     *
     * @type sai_acl_field_data_t sai_ip4_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_INNER_DST_IP,

    /**
     * @brief In-Ports (mask is not needed)
     *
     * @type sai_acl_field_data_t sai_object_list_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_PORT
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_IN_PORTS,

    /**
     * @brief Out-Ports (mask is not needed)
     *
     * @type sai_acl_field_data_t sai_object_list_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_PORT
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_OUT_PORTS,

    /**
     * @brief In-Port (mask is not needed)
     *
     * @type sai_acl_field_data_t sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_PORT, SAI_OBJECT_TYPE_LAG
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_IN_PORT,

    /**
     * @brief Out-Port (mask is not needed)
     *
     * @type sai_acl_field_data_t sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_PORT, SAI_OBJECT_TYPE_LAG
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_OUT_PORT,

    /**
     * @brief Source port which could be a physical or LAG port
     * (mask is not needed)
     *
     * @type sai_acl_field_data_t sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_PORT
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_SRC_PORT,

    /**
     * @brief Outer Vlan Id (12 bits)
     *
     * @type sai_acl_field_data_t sai_uint16_t
     * @flags CREATE_AND_SET
     * @isvlan true
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_OUTER_VLAN_ID,

    /**
     * @brief Outer Vlan Priority (3 bits)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_OUTER_VLAN_PRI,

    /**
     * @brief Outer Vlan CFI (1 bit)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_OUTER_VLAN_CFI,

    /**
     * @brief Inner Vlan Id (12 bits)
     *
     * @type sai_acl_field_data_t sai_uint16_t
     * @flags CREATE_AND_SET
     * @isvlan true
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_INNER_VLAN_ID,

    /**
     * @brief Inner Vlan Priority (3 bits)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_INNER_VLAN_PRI,

    /**
     * @brief Inner Vlan CFI (1 bit)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_INNER_VLAN_CFI,

    /**
     * @brief L4 Src Port
     *
     * @type sai_acl_field_data_t sai_uint16_t
     * @flags CREATE_AND_SET
     * @isvlan false
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_L4_SRC_PORT,

    /**
     * @brief L4 Dst Port
     *
     * @type sai_acl_field_data_t sai_uint16_t
     * @flags CREATE_AND_SET
     * @isvlan false
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_L4_DST_PORT,

    /**
     * @brief Inner L4 Src Port
     *
     * @type sai_acl_field_data_t sai_uint16_t
     * @flags CREATE_AND_SET
     * @isvlan false
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_INNER_L4_SRC_PORT,

    /**
     * @brief Inner L4 Dst Port
     *
     * @type sai_acl_field_data_t sai_uint16_t
     * @flags CREATE_AND_SET
     * @isvlan false
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_INNER_L4_DST_PORT,

    /**
     * @brief EtherType
     *
     * @type sai_acl_field_data_t sai_uint16_t
     * @flags CREATE_AND_SET
     * @isvlan false
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_ETHER_TYPE,

    /**
     * @brief Inner EtherType
     *
     * @type sai_acl_field_data_t sai_uint16_t
     * @flags CREATE_AND_SET
     * @isvlan false
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_INNER_ETHER_TYPE,

    /**
     * @brief IP Protocol
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_IP_PROTOCOL,

    /**
     * @brief Inner IP Protocol
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_INNER_IP_PROTOCOL,

    /**
     * @brief IP Identification
     *
     * @type sai_acl_field_data_t sai_uint16_t
     * @flags CREATE_AND_SET
     * @isvlan false
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_IP_IDENTIFICATION,

    /**
     * @brief IP DSCP (6 bits)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_DSCP,

    /**
     * @brief IP ECN (2 bits)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_ECN,

    /**
     * @brief IP TTL
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_TTL,

    /**
     * @brief IP TOS
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_TOS,

    /**
     * @brief IP Flags (3 bits)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_IP_FLAGS,

    /**
     * @brief TCP Flags (6 bits)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_TCP_FLAGS,

    /**
     * @brief IP Type (field mask is not needed)
     *
     * @type sai_acl_field_data_t sai_acl_ip_type_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_ACL_IP_TYPE,

    /**
     * @brief IP Frag (field mask is not needed)
     *
     * @type sai_acl_field_data_t sai_acl_ip_frag_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_ACL_IP_FRAG,

    /**
     * @brief IPv6 Flow Label (20 bits)
     *
     * @type sai_acl_field_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_IPV6_FLOW_LABEL,

    /**
     * @brief Class-of-Service (Traffic Class)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_TC,

    /**
     * @brief ICMP Type
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_ICMP_TYPE,

    /**
     * @brief ICMP Code
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_ICMP_CODE,

    /**
     * @brief ICMP Type for IPv6
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_ICMPV6_TYPE,

    /**
     * @brief ICMP Code for IPv6
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_ICMPV6_CODE,

    /**
     * @brief Number of VLAN Tags
     *
     * @type sai_acl_field_data_t sai_packet_vlan_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_PACKET_VLAN,

    /**
     * @brief Tunnel VNI
     *
     * @type sai_acl_field_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_TUNNEL_VNI,

    /**
     * @brief Match on packet that has vlan tag
     *
     * @type sai_acl_field_data_t bool
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_HAS_VLAN_TAG,

    /**
     * @brief SCI value in MACsec packet SecTAG
     *
     * @type sai_acl_field_data_t sai_uint64_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_MACSEC_SCI,

    /**
     * @brief Label value for MPLS label on the top
     *
     * @type sai_acl_field_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_MPLS_LABEL0_LABEL,

    /**
     * @brief TTL value for MPLS label on the top
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_MPLS_LABEL0_TTL,

    /**
     * @brief EXP value for MPLS label on the top (3 bits)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_MPLS_LABEL0_EXP,

    /**
     * @brief BOS bit value for MPLS label on the top
     *
     * @type sai_acl_field_data_t bool
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_MPLS_LABEL0_BOS,

    /**
     * @brief Label value for second MPLS label from the top
     *
     * @type sai_acl_field_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_MPLS_LABEL1_LABEL,

    /**
     * @brief TTL value for second MPLS label from the top
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_MPLS_LABEL1_TTL,

    /**
     * @brief EXP value for second MPLS label from the top (3 bits)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_MPLS_LABEL1_EXP,

    /**
     * @brief BOS bit value for second MPLS label from the top
     *
     * @type sai_acl_field_data_t bool
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_MPLS_LABEL1_BOS,

    /**
     * @brief Label value for third MPLS label from the top
     *
     * @type sai_acl_field_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_MPLS_LABEL2_LABEL,

    /**
     * @brief TTL value for third MPLS label from the top
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_MPLS_LABEL2_TTL,

    /**
     * @brief EXP value for third MPLS label on the top (3 bits)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_MPLS_LABEL2_EXP,

    /**
     * @brief BOS bit value for third MPLS label from the top
     *
     * @type sai_acl_field_data_t bool
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_MPLS_LABEL2_BOS,

    /**
     * @brief Label value for fourth MPLS label from the top
     *
     * @type sai_acl_field_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_MPLS_LABEL3_LABEL,

    /**
     * @brief TTL value for fourth MPLS label from the top
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_MPLS_LABEL3_TTL,

    /**
     * @brief EXP value for fourth MPLS label on the top (3 bits)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_MPLS_LABEL3_EXP,

    /**
     * @brief BOS bit value for fourth MPLS label from the top
     *
     * @type sai_acl_field_data_t bool
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_MPLS_LABEL3_BOS,

    /**
     * @brief Label value for fifth MPLS label from the top
     *
     * @type sai_acl_field_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_MPLS_LABEL4_LABEL,

    /**
     * @brief TTL value for fifth MPLS label from the top
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_MPLS_LABEL4_TTL,

    /**
     * @brief EXP value for fifth MPLS label on the top (3 bits)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_MPLS_LABEL4_EXP,

    /**
     * @brief BOS bit value for fifth MPLS label from the top
     *
     * @type sai_acl_field_data_t bool
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_MPLS_LABEL4_BOS,

    /* User Based metadata */

    /**
     * @brief DST MAC address match user meta data in FDB
     *
     * Value must be in the range defined in
     * #SAI_SWITCH_ATTR_FDB_DST_USER_META_DATA_RANGE
     *
     * @type sai_acl_field_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_FDB_DST_USER_META,

    /**
     * @brief DST IP address match user meta data in Route Table
     *
     * Value must be in the range defined in
     * #SAI_SWITCH_ATTR_ROUTE_DST_USER_META_DATA_RANGE
     *
     * @type sai_acl_field_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_ROUTE_DST_USER_META,

    /**
     * @brief DST IP address match user meta data in Neighbor Table
     *
     * Value must be in the range defined in
     * #SAI_SWITCH_ATTR_NEIGHBOR_DST_USER_META_DATA_RANGE
     *
     * @type sai_acl_field_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_NEIGHBOR_DST_USER_META,

    /**
     * @brief Port User metadata
     *
     * Value must be in the range defined in
     * SAI_SWITCH_ATTR_PORT_USER_META_DATA_RANGE
     *
     * @type sai_acl_field_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_PORT_USER_META,

    /**
     * @brief Vlan User metadata
     *
     * Value must be in the range defined in
     * #SAI_SWITCH_ATTR_VLAN_USER_META_DATA_RANGE
     *
     * @type sai_acl_field_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_VLAN_USER_META,

    /**
     * @brief Metadata carried from previous ACL stage.
     *
     * When an ACL entry set the meta data, the ACL metadata
     * form previous stages are overridden.
     * Value must be in the range defined in
     * #SAI_SWITCH_ATTR_ACL_USER_META_DATA_RANGE
     *
     * @type sai_acl_field_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_ACL_USER_META,

    /* NPU Based metadata [bool] */

    /**
     * @brief DST MAC address match in FDB
     *
     * @type sai_acl_field_data_t bool
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_FDB_NPU_META_DST_HIT,

    /**
     * @brief DST IP address match in neighbor Table
     *
     * @type sai_acl_field_data_t bool
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_NEIGHBOR_NPU_META_DST_HIT,

    /**
     * @brief DST IP address match in Route Table
     *
     * @type sai_acl_field_data_t bool
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_ROUTE_NPU_META_DST_HIT,

    /**
     * @brief Base Transport Header opcode field
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_BTH_OPCODE,

    /**
     * @brief Ack_extented Transport Header syndrome field
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_AETH_SYNDROME,

    /**
     * @brief User Defined Field object for the UDF Groups in ACL Table
     *
     * @type sai_acl_field_data_t sai_u8_list_t
     * @flags CREATE_AND_SET
     * @default disabled
     * @range SAI_ACL_USER_DEFINED_FIELD_ATTR_ID_RANGE
     */
    SAI_ACL_ENTRY_ATTR_USER_DEFINED_FIELD_GROUP_MIN,

    /**
     * @brief User Defined Field data max
     *
     * @type sai_acl_field_data_t sai_u8_list_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_USER_DEFINED_FIELD_GROUP_MAX = SAI_ACL_ENTRY_ATTR_USER_DEFINED_FIELD_GROUP_MIN + SAI_ACL_USER_DEFINED_FIELD_ATTR_ID_RANGE,

    /**
     * @brief Range Type defined in sai_acl_range_type_t
     *
     * List of SAI ACL Range Object Id
     *
     * @type sai_acl_field_data_t sai_object_list_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_ACL_RANGE
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_ACL_RANGE_TYPE,

    /**
     * @brief IPv6 Next Header (8 bits)
     *
     * This is to qualify 6th Byte value in IPv6 header.
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_IPV6_NEXT_HEADER,

    /**
     * @brief GRE Key (32 bits)
     *
     * @type sai_acl_field_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_GRE_KEY,

    /**
     * @brief TAM INT type
     *
     * @type sai_acl_field_data_t sai_tam_int_type_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_FIELD_TAM_INT_TYPE,

    /**
     * @brief End of Rule Match Fields
     */
    SAI_ACL_ENTRY_ATTR_FIELD_END = SAI_ACL_ENTRY_ATTR_FIELD_TAM_INT_TYPE,

    /*
     * Actions [sai_acl_action_data_t]
     *
     * - To enable an action, parameter is needed unless noted specifically.
     * - To disable an action, parameter is not needed.
     */

    /**
     * @brief Start of Rule Actions
     */
    SAI_ACL_ENTRY_ATTR_ACTION_START = 0x00002000,

    /**
     * @brief Redirect Packet to a destination which can be a port, system port,
     * LAG, nexthop, nexthopgroup, bridge port, L2MC group,IPMC group
     *
     * When redirecting to a bridge port, the following behavior will happen according to the bridge port type:
     * SAI_BRIDGE_PORT_TYPE_PORT - Forward to bridge port, egress vlan will be the pipeline vlan
     * SAI_BRIDGE_PORT_TYPE_SUB_PORT - Forward to bridge port, egress vlan will be according to corresponding bridge port
     * SAI_BRIDGE_PORT_TYPE_1Q_ROUTER - Forward to router. RIF will be according to the outer vlan value in the pipeline
     * SAI_BRIDGE_PORT_TYPE_1D_ROUTER - Forward to router. RIF will be the corresponding 1d bridge RIF
     * SAI_BRIDGE_PORT_TYPE_TUNNEL - ACL based encap. Tunnel ID will be according to the corresponding bridge port. In
     * this case, it is mandatory to also supply action endpoint, with endpoint IP value
     *
     * @type sai_acl_action_data_t sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_PORT, SAI_OBJECT_TYPE_SYSTEM_PORT, SAI_OBJECT_TYPE_LAG, SAI_OBJECT_TYPE_NEXT_HOP, SAI_OBJECT_TYPE_NEXT_HOP_GROUP, SAI_OBJECT_TYPE_BRIDGE_PORT, SAI_OBJECT_TYPE_L2MC_GROUP, SAI_OBJECT_TYPE_IPMC_GROUP
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_REDIRECT = SAI_ACL_ENTRY_ATTR_ACTION_START,

    /**
     * @brief Tunnel Endpoint IP. mandatory and valid only when redirect action is to SAI_BRIDGE_PORT_TYPE_TUNNEL
     *
     * @type sai_acl_action_data_t sai_ip_address_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_ENDPOINT_IP,

    /**
     * @brief Redirect Packet to a list of destination which can be
     * a port list.
     *
     * This action is deprecated and will be removed in future release. In order to achieve the functionality,
     * please use redirect action with next hop group or L2MC group or IPMC group.
     *
     * @type sai_acl_action_data_t sai_object_list_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_PORT, SAI_OBJECT_TYPE_SYSTEM_PORT, SAI_OBJECT_TYPE_LAG, SAI_OBJECT_TYPE_NEXT_HOP, SAI_OBJECT_TYPE_NEXT_HOP_GROUP
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_REDIRECT_LIST,

    /**
     * @brief Packet Action
     *
     * @type sai_acl_action_data_t sai_packet_action_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_PACKET_ACTION,

    /**
     * @brief Flood Packet on Vlan domain (parameter is not needed)
     *
     * @type sai_acl_action_data_t sai_int32_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_FLOOD,

    /**
     * @brief Attach/detach counter id to the entry
     *
     * @type sai_acl_action_data_t sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_ACL_COUNTER
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_COUNTER,

    /**
     * @brief Ingress Mirror (mirror session id list)
     *
     * @type sai_acl_action_data_t sai_object_list_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_MIRROR_SESSION
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_MIRROR_INGRESS,

    /**
     * @brief Egress Mirror (mirror session id list)
     *
     * @type sai_acl_action_data_t sai_object_list_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_MIRROR_SESSION
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_MIRROR_EGRESS,

    /**
     * @brief Associate with policer
     *
     * @type sai_acl_action_data_t sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_POLICER
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_POLICER,

    /**
     * @brief Decrement TTL (enable/disable)
     *
     * @type sai_acl_action_data_t bool
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_DECREMENT_TTL,

    /**
     * @brief Set Class-of-Service (Traffic Class)
     *
     * @type sai_acl_action_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_TC,

    /**
     * @brief Set packet color
     *
     * @type sai_acl_action_data_t sai_packet_color_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_PACKET_COLOR,

    /**
     * @brief Set Packet Inner Vlan Id (12 bits)
     *
     * @type sai_acl_action_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_INNER_VLAN_ID,

    /**
     * @brief Set Packet Inner Vlan Priority (3 bits)
     *
     * @type sai_acl_action_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_INNER_VLAN_PRI,

    /**
     * @brief Set Packet Outer Vlan Id (12 bits)
     *
     * @type sai_acl_action_data_t sai_uint16_t
     * @flags CREATE_AND_SET
     * @isvlan true
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_OUTER_VLAN_ID,

    /**
     * @brief Set Packet Outer Vlan Priority (3 bits)
     *
     * @type sai_acl_action_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_OUTER_VLAN_PRI,

    /**
     * @brief Add Packet Vlan Id (12 bits)
     *
     * @type sai_acl_action_data_t sai_uint16_t
     * @flags CREATE_AND_SET
     * @isvlan true
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_ADD_VLAN_ID,

    /**
     * @brief Add Packet Vlan Priority (3 bits)
     *
     * @type sai_acl_action_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_ADD_VLAN_PRI,

    /**
     * @brief Set Packet Src MAC Address
     *
     * @type sai_acl_action_data_t sai_mac_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_SRC_MAC,

    /**
     * @brief Set Packet Dst MAC Address
     *
     * @type sai_acl_action_data_t sai_mac_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_DST_MAC,

    /**
     * @brief Set Packet Src IPv4 Address
     *
     * @type sai_acl_action_data_t sai_ip4_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_SRC_IP,

    /**
     * @brief Set Packet Src IPv4 Address
     *
     * @type sai_acl_action_data_t sai_ip4_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_DST_IP,

    /**
     * @brief Set Packet Src IPv6 Address
     *
     * @type sai_acl_action_data_t sai_ip6_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_SRC_IPV6,

    /**
     * @brief Set Packet Src IPv6 Address
     *
     * @type sai_acl_action_data_t sai_ip6_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_DST_IPV6,

    /**
     * @brief Set Packet DSCP (6 bits)
     *
     * @type sai_acl_action_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_DSCP,

    /**
     * @brief Set Packet ECN (2 bits)
     *
     * @type sai_acl_action_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_ECN,

    /**
     * @brief Set Packet L4 Src Port
     *
     * @type sai_acl_action_data_t sai_uint16_t
     * @flags CREATE_AND_SET
     * @isvlan false
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_L4_SRC_PORT,

    /**
     * @brief Set Packet L4 Src Port
     *
     * @type sai_acl_action_data_t sai_uint16_t
     * @flags CREATE_AND_SET
     * @isvlan false
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_L4_DST_PORT,

    /**
     * @brief Set ingress packet sampling (sample packet session id)
     *
     * @type sai_acl_action_data_t sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_SAMPLEPACKET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_INGRESS_SAMPLEPACKET_ENABLE,

    /**
     * @brief Set egress packet sampling (sample packet session id)
     *
     * @type sai_acl_action_data_t sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_SAMPLEPACKET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_EGRESS_SAMPLEPACKET_ENABLE,

    /**
     * @brief Set metadata to carry forward to next ACL Stage
     *
     * Value Range #SAI_SWITCH_ATTR_ACL_USER_META_DATA_RANGE
     *
     * @type sai_acl_action_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_ACL_META_DATA,

    /**
     * @brief Egress block port list
     *
     * This action would be deprecated in future release. To achieve this
     * functionality use isolation group.
     *
     * Packets matching the ACL entry and egressing out of the ports in the
     * given port list will be dropped.
     *
     * @type sai_acl_action_data_t sai_object_list_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_PORT
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_EGRESS_BLOCK_PORT_LIST,

    /**
     * @brief Set User Defined Trap ID
     *
     * Copy packet action mandatory to be present (Copy/Trap/Log)
     * Value Range #SAI_SWITCH_ATTR_ACL_USER_TRAP_ID_RANGE
     *
     * @type sai_acl_action_data_t sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_HOSTIF_USER_DEFINED_TRAP
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_USER_TRAP_ID,

    /**
     * @brief Do Not Learn unknown source MAC on match(enable/disable) (parameter is not needed)
     *
     * @type sai_acl_action_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_DO_NOT_LEARN,

    /**
     * @brief DTEL flow operation
     *
     * @warning experimental
     *
     * @type sai_acl_action_data_t sai_acl_dtel_flow_op_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_ACL_DTEL_FLOW_OP,

    /**
     * @brief DTEL INT session ID
     *
     * @warning experimental
     *
     * @type sai_acl_action_data_t sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_DTEL_INT_SESSION
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_DTEL_INT_SESSION,

    /**
     * @brief Enable DTEL drop report
     *
     * @warning experimental
     *
     * @type sai_acl_action_data_t bool
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_DTEL_DROP_REPORT_ENABLE,

    /**
     * @brief Enable DTEL tail drop reporting
     *
     * @warning experimental
     *
     * @type sai_acl_action_data_t bool
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_DTEL_TAIL_DROP_REPORT_ENABLE,

    /**
     * @brief DTEL flow sample percentage
     *
     * @warning experimental
     *
     * @type sai_acl_action_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_DTEL_FLOW_SAMPLE_PERCENT,

    /**
     * @brief Enable DTEL report for all packets without filtering
     *
     * @warning experimental
     *
     * @type sai_acl_action_data_t bool
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_DTEL_REPORT_ALL_PACKETS,

    /**
     * @brief Set NAT exception rule
     *
     * @type sai_acl_action_data_t bool
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_NO_NAT,

    /**
     * @brief Enable INT metadata insertion
     *
     * @type sai_acl_action_data_t bool
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_INT_INSERT,

    /**
     * @brief Enable INT metadata deletion
     *
     * @type sai_acl_action_data_t bool
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_INT_DELETE,

    /**
     * @brief Enable INT metadata reports
     *
     * @type sai_acl_action_data_t bool
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_INT_REPORT_FLOW,

    /**
     * @brief Enable INT drop reports
     *
     * @type sai_acl_action_data_t bool
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_INT_REPORT_DROPS,

    /**
     * @brief Enable INT tail drop reports
     *
     * @type sai_acl_action_data_t bool
     * @flags CREATE_AND_SET
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_INT_REPORT_TAIL_DROPS,

    /**
     * @brief ACL bind point for TAM INT object
     *
     * Bind (or unbind) a TAM INT object.
     * Note that an ACL entry may bind a TAM INT object, or conversely a
     * TAM INT object may bind an ACL table or ACL group. In the latter
     * case, SAI_NULL_OBJECT_ID should be assigned as the attribute value.
     *
     * Note: Applicable only when SAI_ACL_ENTRY_ATTR_ACTION_INT_INSERT == true or SAI_ACL_ENTRY_ATTR_ACTION_INT_DELETE == true or SAI_ACL_ENTRY_ATTR_ACTION_INT_REPORT_FLOW == true or SAI_ACL_ENTRY_ATTR_ACTION_INT_REPORT_DROPS == true or SAI_ACL_ENTRY_ATTR_ACTION_INT_REPORT_TAIL_DROPS == true
     *
     * @type sai_acl_action_data_t sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_TAM_INT
     * @allownull true
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_TAM_INT_OBJECT,

    /**
     * @brief Set isolation group (isolation group object id)
     *
     * @type sai_acl_action_data_t sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_ISOLATION_GROUP
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_ISOLATION_GROUP,

    /**
     * @brief MACsec flow
     *
     * @type sai_acl_action_data_t sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_MACSEC_FLOW
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_MACSEC_FLOW,

    /**
     * @brief LAG Hash ID
     *
     * @type sai_acl_action_data_t sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_HASH
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_LAG_HASH_ID,

    /**
     * @brief ECMP Hash ID
     *
     * @type sai_acl_action_data_t sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_HASH
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_ECMP_HASH_ID,

    /**
     * @brief Set virtual router
     *
     * @type sai_acl_action_data_t sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_VIRTUAL_ROUTER
     * @default disabled
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_VRF,

    /**
     * @brief End of Rule Actions
     */
    SAI_ACL_ENTRY_ATTR_ACTION_END = SAI_ACL_ENTRY_ATTR_ACTION_SET_VRF,

    /**
     * @brief End of ACL Entry attributes
     */
    SAI_ACL_ENTRY_ATTR_END,

    /** Custom range base value */
    SAI_ACL_ENTRY_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_ACL_ENTRY_ATTR_CUSTOM_RANGE_END

} sai_acl_entry_attr_t;

/**
 * @brief Attribute Id for sai_acl_counter
 */
typedef enum _sai_acl_counter_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_ACL_COUNTER_ATTR_START,

    /**
     * @brief SAI ACL table object id
     *
     * @type sai_object_id_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @objects SAI_OBJECT_TYPE_ACL_TABLE
     */
    SAI_ACL_COUNTER_ATTR_TABLE_ID = SAI_ACL_COUNTER_ATTR_START,

    /*
     * By default, Byte Counter would be created and following
     * use of the below attributes would result in an error.
     *
     * - Both packet count and byte count set to disable
     * - Only Byte count used which is set to disable
     */

    /**
     * @brief Enable/disable packet count
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_COUNTER_ATTR_ENABLE_PACKET_COUNT,

    /**
     * @brief Enable/disable byte count
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_COUNTER_ATTR_ENABLE_BYTE_COUNT,

    /**
     * @brief Get/set packet count
     *
     * @type sai_uint64_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_ACL_COUNTER_ATTR_PACKETS,

    /**
     * @brief Get/set byte count
     *
     * @type sai_uint64_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_ACL_COUNTER_ATTR_BYTES,

    /**
     * @brief End of attributes
     */
    SAI_ACL_COUNTER_ATTR_END,

    /** Custom range base value */
    SAI_ACL_COUNTER_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_ACL_COUNTER_ATTR_CUSTOM_RANGE_END

} sai_acl_counter_attr_t;

/**
 * @brief Attribute data for ACL Range Type
 */
typedef enum _sai_acl_range_type_t
{
    /** L4 Source Port Range */
    SAI_ACL_RANGE_TYPE_L4_SRC_PORT_RANGE,

    /** L4 Destination Port Range */
    SAI_ACL_RANGE_TYPE_L4_DST_PORT_RANGE,

    /** Outer Vlan Range */
    SAI_ACL_RANGE_TYPE_OUTER_VLAN,

    /** Inner Vlan Range */
    SAI_ACL_RANGE_TYPE_INNER_VLAN,

    /** Packet Length Range in bytes */
    SAI_ACL_RANGE_TYPE_PACKET_LENGTH

} sai_acl_range_type_t;

/**
 * @brief Attribute Id for ACL Range Object
 */
typedef enum _sai_acl_range_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_ACL_RANGE_ATTR_START,

    /**
     * @brief Range type
     *
     * Mandatory to pass only one of the range types
     * defined in sai_acl_range_type_t enum during ACL Range Creation.
     * Range Type cannot be changed after the range is created.
     *
     * @type sai_acl_range_type_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_ACL_RANGE_ATTR_TYPE = SAI_ACL_RANGE_ATTR_START,

    /**
     * @brief Start and End of ACL Range
     *
     * Range will include the start and end values.
     * Range Limit cannot be changed after the range is created.
     *
     * @type sai_u32_range_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_ACL_RANGE_ATTR_LIMIT,

    /**
     * @brief End of attributes
     */
    SAI_ACL_RANGE_ATTR_END,

    /** Custom range base value */
    SAI_ACL_RANGE_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_ACL_RANGE_ATTR_CUSTOM_RANGE_END

} sai_acl_range_attr_t;

/**
 * @brief Create an ACL table
 *
 * @param[out] acl_table_id The ACL table id
 * @param[in] switch_id Switch Object id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_acl_table_fn)(
        _Out_ sai_object_id_t *acl_table_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Delete an ACL table
 *
 * @param[in] acl_table_id The ACL table id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_acl_table_fn)(
        _In_ sai_object_id_t acl_table_id);

/**
 * @brief Set ACL table attribute
 *
 * @param[in] acl_table_id The ACL table id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_acl_table_attribute_fn)(
        _In_ sai_object_id_t acl_table_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get ACL table attribute
 *
 * @param[in] acl_table_id ACL table id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_acl_table_attribute_fn)(
        _In_ sai_object_id_t acl_table_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create an ACL entry
 *
 * @param[out] acl_entry_id The ACL entry id
 * @param[in] switch_id The Switch Object id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_acl_entry_fn)(
        _Out_ sai_object_id_t *acl_entry_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Delete an ACL entry
 *
 * @param[in] acl_entry_id The ACL entry id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_acl_entry_fn)(
        _In_ sai_object_id_t acl_entry_id);

/**
 * @brief Set ACL entry attribute
 *
 * @param[in] acl_entry_id The ACL entry id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_acl_entry_attribute_fn)(
        _In_ sai_object_id_t acl_entry_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get ACL entry attribute
 *
 * @param[in] acl_entry_id ACL entry id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_acl_entry_attribute_fn)(
        _In_ sai_object_id_t acl_entry_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create an ACL counter
 *
 * @param[out] acl_counter_id The ACL counter id
 * @param[in] switch_id The switch Object id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_acl_counter_fn)(
        _Out_ sai_object_id_t *acl_counter_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Delete an ACL counter
 *
 * @param[in] acl_counter_id The ACL counter id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_acl_counter_fn)(
        _In_ sai_object_id_t acl_counter_id);

/**
 * @brief Set ACL counter attribute
 *
 * @param[in] acl_counter_id The ACL counter id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_acl_counter_attribute_fn)(
        _In_ sai_object_id_t acl_counter_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get ACL counter attribute
 *
 * @param[in] acl_counter_id ACL counter id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_acl_counter_attribute_fn)(
        _In_ sai_object_id_t acl_counter_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create an ACL Range
 *
 * @param[out] acl_range_id The ACL range id
 * @param[in] switch_id The Switch object id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_acl_range_fn)(
        _Out_ sai_object_id_t *acl_range_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove an ACL Range
 *
 * @param[in] acl_range_id The ACL range id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_acl_range_fn)(
        _In_ sai_object_id_t acl_range_id);

/**
 * @brief Set ACL range attribute
 *
 * @param[in] acl_range_id The ACL range id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_acl_range_attribute_fn)(
        _In_ sai_object_id_t acl_range_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get ACL range attribute
 *
 * @param[in] acl_range_id ACL range id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_acl_range_attribute_fn)(
        _In_ sai_object_id_t acl_range_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create an ACL Table Group
 *
 * @param[out] acl_table_group_id The ACL group id
 * @param[in] switch_id Switch ID
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_acl_table_group_fn)(
        _Out_ sai_object_id_t *acl_table_group_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Delete an ACL Group
 *
 * @param[in] acl_table_group_id The ACL group id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_acl_table_group_fn)(
        _In_ sai_object_id_t acl_table_group_id);

/**
 * @brief Set ACL table group attribute
 *
 * @param[in] acl_table_group_id The ACL table group id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_acl_table_group_attribute_fn)(
        _In_ sai_object_id_t acl_table_group_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get ACL table group attribute
 *
 * @param[in] acl_table_group_id ACL table group id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_acl_table_group_attribute_fn)(
        _In_ sai_object_id_t acl_table_group_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create an ACL Table Group Member
 *
 * @param[out] acl_table_group_member_id The ACL table group member id
 * @param[in] switch_id Switch ID
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_acl_table_group_member_fn)(
        _Out_ sai_object_id_t *acl_table_group_member_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Delete an ACL Group Member
 *
 * @param[in] acl_table_group_member_id The ACL table group member id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_acl_table_group_member_fn)(
        _In_ sai_object_id_t acl_table_group_member_id);

/**
 * @brief Set ACL table group member attribute
 *
 * @param[in] acl_table_group_member_id The ACL table group member id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_acl_table_group_member_attribute_fn)(
        _In_ sai_object_id_t acl_table_group_member_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get ACL table group member attribute
 *
 * @param[in] acl_table_group_member_id ACL table group member id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_acl_table_group_member_attribute_fn)(
        _In_ sai_object_id_t acl_table_group_member_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Port methods table retrieved with sai_api_query()
 */
typedef struct _sai_acl_api_t
{
    sai_create_acl_table_fn                     create_acl_table;
    sai_remove_acl_table_fn                     remove_acl_table;
    sai_set_acl_table_attribute_fn              set_acl_table_attribute;
    sai_get_acl_table_attribute_fn              get_acl_table_attribute;
    sai_create_acl_entry_fn                     create_acl_entry;
    sai_remove_acl_entry_fn                     remove_acl_entry;
    sai_set_acl_entry_attribute_fn              set_acl_entry_attribute;
    sai_get_acl_entry_attribute_fn              get_acl_entry_attribute;
    sai_create_acl_counter_fn                   create_acl_counter;
    sai_remove_acl_counter_fn                   remove_acl_counter;
    sai_set_acl_counter_attribute_fn            set_acl_counter_attribute;
    sai_get_acl_counter_attribute_fn            get_acl_counter_attribute;
    sai_create_acl_range_fn                     create_acl_range;
    sai_remove_acl_range_fn                     remove_acl_range;
    sai_set_acl_range_attribute_fn              set_acl_range_attribute;
    sai_get_acl_range_attribute_fn              get_acl_range_attribute;
    sai_create_acl_table_group_fn               create_acl_table_group;
    sai_remove_acl_table_group_fn               remove_acl_table_group;
    sai_set_acl_table_group_attribute_fn        set_acl_table_group_attribute;
    sai_get_acl_table_group_attribute_fn        get_acl_table_group_attribute;
    sai_create_acl_table_group_member_fn        create_acl_table_group_member;
    sai_remove_acl_table_group_member_fn        remove_acl_table_group_member;
    sai_set_acl_table_group_member_attribute_fn set_acl_table_group_member_attribute;
    sai_get_acl_table_group_member_attribute_fn get_acl_table_group_member_attribute;
} sai_acl_api_t;

/**
 * @}
 */
#endif /** __SAIACL_H_ */
