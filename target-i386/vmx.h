/*
 * Intel VMX (Virtual Machine Extension) header
 *
 * Copyright (c) 2008 Kevin Wolf
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef VMX_H
#define VMX_H

#define VMCS_REVISION 0x00000000
#define NO_VMCS 0xffffffffffffffffLL

/* See Intel Arch 3b Appendix I */
#define EXCEP_OR_NMI_INT 0x00
#define EXTERN_INT 0x01
#define TRIPLE_FAULT 0x02
#define INIT_SIGNAL 0x03
#define STARTUP_IPI 0x04
#define IO_SMI_INT 0x05
#define SMI_OTHER 0x06
#define INT_WINDOW 0x07
#define NMI_WINDOW 0x08
#define TASK_SWITCH 0x09
#define G_CPUID 0x0a
#define G_GETSEC 0x0b
#define G_HLT 0x0c
#define G_INVD 0x0d
#define G_INVLPG 0x0e
#define G_RDPMC 0x0f
#define G_RDTSC 0x10
#define G_RSM 0x11
#define G_VMCALL 0x12
#define G_VMCLEAR 0x13
#define G_VMLAUNCH 0x14
#define G_VMPTRLD 0x15
#define G_VMPTRST 0x16
#define G_VMREAD 0x17
#define G_VMRESUME 0x18
#define G_VMWRITE 0x19
#define G_VMXOFF 0x1a
#define G_VMXON 0x1b
#define G_CTL_REG 0x1c
#define G_MOV_DR 0x1d
#define G_IO 0x1e
#define G_RDMSR 0x1f
#define G_WRMSR 0x20
#define VM_ENTRY_FAIL_GUEST_STATE 0x21
#define VM_ENTRY_FAIL_MSR_LOAD 0x22
#define G_MWAIT 0x24
#define G_MONITOR 0x27
#define G_PAUSE 0x28
#define VM_ENTRY_FAIL_MACHINE_CHECK 0x29
#define TPR_THRESH 0x2b
#define G_APIC 0x2c
#define G_WBINVD 0x36
#define G_XSETBV 0x37

/* Part of the CPUX86State struct */
typedef struct vmx_status {
	int			 	enabled;
	int             in_non_root;
	uint64_t    	cur_vmcs;
} vmx_status_t;


/* Launch state */
enum {
    VMX_LS_CLEAR = 0,
    VMX_LS_LAUNCHED,
};

/* Virtual MAchine Control Structure */
enum vmcs_field {

	rev_abort = 0,

	guest_cr0,
    guest_cr3,
    guest_cr4,

    guest_es_base,
    guest_cs_base,
    guest_ss_base,
    guest_ds_base,
    guest_fs_base,
    guest_gs_base,
    guest_ldtr_base,
    guest_tr_base,
    guest_gdtr_base,
    guest_idtr_base,

    guest_dr7,
    guest_rsp,
    guest_rip,
    guest_rflags,
    guest_pending_dbg_excp,
    guest_ia32_sysenter_esp,
    guest_ia32_sysenter_eip,

    guest_cs_sel,
    guest_ss_sel,
    guest_ds_sel,
    guest_es_sel,
    guest_fs_sel,
    guest_gs_sel,
    guest_ldtr_sel,
    guest_tr_sel,


    guest_cs_limit,
    guest_ss_limit,
    guest_ds_limit,
    guest_es_limit,
    guest_fs_limit,
    guest_gs_limit,
    guest_ldtr_limit,
    guest_tr_limit,

    guest_cs_access,
    guest_ss_access,
    guest_ds_access,
    guest_es_access,
    guest_fs_access,
    guest_gs_access,
    guest_ldtr_access,
    guest_tr_access,

    guest_gdtr_limit,
    guest_idtr_limit,

    guest_ia32_debugctl,
    guest_ia32_sysenter_cs,
    guest_ia32_perf_global_ctrl,
    guest_ia32_pat,
    guest_ia32_efer,

    guest_smbase,

    guest_activity,
    guest_interruptibility,
    guest_vmcs_link,
    guest_preemtion_timer,
    guest_pdpte0,
    guest_pdpte1,
    guest_pdpte2,
    guest_pdpte3,


    host_cr0,
    host_cr3,
    host_cr4,
    host_fs_base,
    host_gs_base,
    host_tr_base,
    host_gdtr_base,
    host_idtr_base,

    host_ia32_sysenter_esp,
    host_ia32_sysenter_eip,
    host_rsp,
    host_rip,

    host_cs_sel,
    host_ss_sel,
    host_ds_sel,
    host_es_sel,
    host_fs_sel,
    host_gs_sel,
    host_tr_sel,


    host_ia32_sysenter_cs,
    host_ia32_perf_global_ctrl,
    host_ia32_pat,
    host_ia32_efer,

    io_bitmap_a,
    io_bitmap_b,
    vmexit_msr_store,
    vmexit_msr_load,
    vmentry_msr_load,
    executive_vmcs,
    tsc_offset,

    guest_physical,

    pin_vm_exec_ctl,
    cpu_vm_exec_ctl,
    exception_bitmap,
    page_fault_error_code_mask,
    page_fault_error_code_match,
    cr3_target_count,
    vmexit_controls,
    vmexit_msr_store_cnt,
    vmexit_msr_load_cnt,
    vmentry_controls,
    vmentry_msr_load_cnt,
    vmentry_intr_info,
    vmentry_excp_error_code,
    vmentry_instruction_len,

    vm_instruction_error,
    exit_reason,
    vmexit_intr_info,
    vmexit_intr_error_code,
    idt_vectoring_info,
    idt_vectoring_error,
    vmexit_instruction_len,
    vmexit_instruction_info,

    cr0_guest_host_mask,
    cr4_guest_host_mask,
    cr0_read_shadow,
    cr4_read_shadow,
    cr3_target_0,
    cr3_target_1,
    cr3_target_2,
    cr3_target_3,

    exit_qualification,
    io_rcx,
    io_rsi,
    io_rdi,
    io_rip,
    guest_linear_addr,

    /* Private */
    launch_state,

    vmcs_max_field_index

};

struct vmcs_field_index {
    enum vmcs_field field;
    uint16_t index;
};

extern struct vmcs_field_index vmcs_field_index[vmcs_max_field_index];

/* See Intel Arch 3b Appendix J */
enum vm_fail_error {
    VMCALL_ROOT = 1,
    VMCLEAR_INVALID,
    VMCLEAR_VMXON,
    VMLAUNCH_NC_VMCS,
    VMRESUME_NL_VMCS,
    VMRESUME_CORRUPT_VMCS,
    VMENTRY_INVALID_CONTROL,
    VMENTRY_INVALID_HOST_STATE,
    VMPTRLD_INVALID_ADDR,
    VMPTRLD_VMXON_PTR,
    VMPTRLD_BAD_VMCS_REV,
    VMRW_BAD_VMCS_COMP,
    VMWRITE_RO_VMCS_COMP,
    VOID,
    VMXON_VMX_ROOT_MODE,
    VMENTRY_INVALID_VMCS,
    VMENTRY_NL_VMCS,
    VMENTRY_NOT_VMXON_PTR,
    VMCALL_NON_CLEAR_VMCS,
    VMCALL_INVALID_VMEXIT,
    VOID2,
    VMCALL_BAD_MSEG,
    VMXOFF_UNDER_DUAL_SMI_AND_SMM,
    VMCALL_INVALID_SMM_FEATURE,
    VMENTRY_INVALID_VMCS_WHEN_RET_SMM,
    VMENTRY_EVENTS_BLOCKED_BY_MOV_SS
};



/*
typedef struct vmcs {
    uint32_t    revision;
    uint32_t    abort;
    uint64_t    data[vmcs_max_field_index];
} vmcs_t;
*/


#endif
