global load_gdt					; Expose to other files
global InstallGDT				; Expose to other files

load_gdt:
	mov eax, [esp]				; Move the parameters to the eax register
	lgdt [eax]					; Load the gdt from the eax register
	ret 						; return to the calling function


;**********************************
; InstallGDT()
;**********************************
InstallGDT:
	cli 						; clear interrupts
	;pusha						; save registers
	lgdt [toc] 					; load GDT into GDTR
	;sti						; enable interrupts
	;popa						; restore registers
	ret 						; All done

; Offset 0 in GDT: Descriptor code=0
gdt_data:
	dd 0						; null descriptor
	dd 0
; gdt code:
	dw 0FFFFh					; code descriptor
	dw 0						; limit low
	db 0 						; base low
	db 10011010b				; access
	db 11001111b				; granularity
	db 0						; base high

; gdt data:						; data descriptor
	dw 0FFFFh					; limit low (Same as code)
	dw 0 						; base low
	db 0						; base middle
	db 10010010b				; access
	db 11001111b				; granularity
	db 0						; base high

end_of_gdt:
toc:
	dw end_of_gdt - gdt_data - 1; limit (Size of GDT)
	dd gdt_data					; base of GDT