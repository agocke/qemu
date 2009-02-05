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
#define NO_VMCS 0xffffffffffffffffL

/* Part of the CPUX86State struct */
typedef struct vmx_status {
	int			 	enabled;
	target_ulong	cur_vmcs;
} vmx_status_t;

/* Virtual MAchine Control Structure */
enum vmcs_field {

    guest_cr0 = 0,
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

/*
typedef struct vmcs {
    uint32_t    revision;
    uint32_t    abort;
    uint64_t    data[vmcs_max_field_index];
} vmcs_t;
*/


#endif
