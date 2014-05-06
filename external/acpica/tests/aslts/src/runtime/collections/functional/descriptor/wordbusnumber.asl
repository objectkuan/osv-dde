/*
 * Some or all of this work - Copyright (c) 2006 - 2013, Intel Corp.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * Neither the name of Intel Corporation nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Resource Descriptor macros
 *
 * Word Bus Number Resource Descriptor Macro
 */

Name (p428, Package() {

	// Byte 4 (General Flags) of Word Address Space Descriptor

	ResourceTemplate () {
		WordBusNumber (ResourceProducer, MinNotFixed, MaxNotFixed, PosDecode,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff)
	},
	ResourceTemplate () {
		WordBusNumber (ResourceProducer, MinNotFixed, MaxNotFixed, SubDecode,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff)
	},
	ResourceTemplate () {
		WordBusNumber (ResourceProducer, MinNotFixed, MaxFixed, PosDecode,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff)
	},
	ResourceTemplate () {
		WordBusNumber (ResourceProducer, MinNotFixed, MaxFixed, SubDecode,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff)
	},
	ResourceTemplate () {
		WordBusNumber (ResourceProducer, MinFixed, MaxNotFixed, PosDecode,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff)
	},
	ResourceTemplate () {
		WordBusNumber (ResourceProducer, MinFixed, MaxNotFixed, SubDecode,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff)
	},
	ResourceTemplate () {
		WordBusNumber (ResourceProducer, MinFixed, MaxFixed, PosDecode,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff)
	},
	ResourceTemplate () {
		WordBusNumber (ResourceProducer, MinFixed, MaxFixed, SubDecode,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff)
	},
	ResourceTemplate () {
		WordBusNumber (ResourceConsumer, MinNotFixed, MaxNotFixed, PosDecode,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff)
	},
	ResourceTemplate () {
		WordBusNumber (ResourceConsumer, MinNotFixed, MaxNotFixed, SubDecode,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff)
	},
	ResourceTemplate () {
		WordBusNumber (ResourceConsumer, MinNotFixed, MaxFixed, PosDecode,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff)
	},
	ResourceTemplate () {
		WordBusNumber (ResourceConsumer, MinNotFixed, MaxFixed, SubDecode,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff)
	},
	ResourceTemplate () {
		WordBusNumber (ResourceConsumer, MinFixed, MaxNotFixed, PosDecode,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff)
	},
	ResourceTemplate () {
		WordBusNumber (ResourceConsumer, MinFixed, MaxNotFixed, SubDecode,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff)
	},
	ResourceTemplate () {
		WordBusNumber (ResourceConsumer, MinFixed, MaxFixed, PosDecode,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff)
	},
	ResourceTemplate () {
		WordBusNumber (ResourceConsumer, MinFixed, MaxFixed, SubDecode,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff)
	},

	// Particular cases

	ResourceTemplate () {
		WordBusNumber ( , , , ,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff)
	},
	ResourceTemplate () {
		WordBusNumber ( , , , ,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff, )
	},

	// Resource Source

	ResourceTemplate () {
		WordBusNumber ( , , , ,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff,
			0x01, "")
	},
	ResourceTemplate () {
		WordBusNumber ( , , , ,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff,
			0x0f, "P")
	},
	ResourceTemplate () {
		WordBusNumber ( , , , ,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff,
			0xf0, "PATH")
	},
	ResourceTemplate () {
		WordBusNumber ( , , , ,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff,
			0xff,
			"!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~ !\"#$%&'()*",
			)
	},

	// Particular cases

	ResourceTemplate () {
		WordBusNumber (ResourceConsumer, MinFixed, MaxFixed, SubDecode,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff,
			0xff, "PATHPATHPATH", WBN0)
	},
	ResourceTemplate () {
		WordBusNumber (ResourceConsumer, MinFixed, MaxFixed, SubDecode,
			0, 0, 0, 0, 0,
			0xff, "PATHPATHPATH", )
	},

	// 20051021, relaxation for omitted ResourceSource (bug-fix 70 rejection)
	ResourceTemplate () {
		WordBusNumber ( , , , ,
			0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff,
			0x0f)
	},
})

/*
ACPI Specification, Revision 3.0, September 2, 2004
6.4.3.5.3   Word Address Space Descriptor

Bus Number Word Address Space Descriptor layout:

Byte 0 (Tag Bits): Value=10001000B (0x88) (Type = 1, Large item name = 0x8)
Byte 1 (Length, bits[7:0]): Variable: Value = 13 (minimum)
Byte 2 (Length, bits[15:8]): Variable: Value = 0 (minimum)
Byte 3 (Resource Type):
	2		Bus number range
Byte 4 (General Flags):
	Bits[7:4] 	Reserved (must be 0)
	Bit[3] 		Min Address Fixed, _MAF:
			1	The specified maximum address is fixed
			0	The specified maximum address is not fixed
				and can be changed
	Bit[2] 		Max Address Fixed,_MIF:
			1	The specified minimum address is fixed
			0	The specified minimum address is not fixed
				and can be changed
	Bit[1] 		Decode Type, _DEC:
			1	This bridge subtractively decodes this address
	 	 	 	(top level bridges only)
			0	This bridge positively decodes this address
	Bit[0] 		Consumer/Producer:
			1-This device consumes this resource
			0-This device produces and consumes this resource
Byte 5 (Type Specific Flags):
		Flags that are specific to each resource type. The meaning of the flags
		in this field depends on the value of the Resource Type field (see above)
	Bit[7:0]	Reserved (must be 0)
Byte 6 (Address space granularity, _GRA bits[7:0]):
	A set bit in this mask means that this bit is decoded. All bits less
	significant than the most significant set bit must be set. (in other
	words, the value of the full Address Space Granularity field (all 16
	bits) must be a number (2**n-1).
Byte 7 (Address space granularity, _GRA bits[15:8])
Byte 8 (Address range minimum, _MIN bits [7:0]):
	For bridges that translate addresses, this is the address space
	on the secondary side of the bridge
Byte 9 (Address range minimum, _MIN bits[15:8])
Byte 10 (Address range maximum, _MAX bits [7:0]): See comment for _MIN
Byte 11 (Address range maximum, _MAX bits[15:8])
Byte 12 (Address Translation offset, _TRA bits [7:0]):
	For bridges that translate addresses across the bridge, this is the
	offset that must be added to the address on the secondary side to obtain
	the address on the primary side. Non-bridge devices must list 0 for all
	Address Translation offset bits
Byte 13 (Address Translation offset, _TRA bits[15:8])
Byte 14 (Address Length, _LEN bits [7:0])
Byte 15 (Address Length, _LEN bits[15:8])
Byte 16 (Resource Source Index):
	(Optional) Only present if Resource Source (below) is present. This
	field gives an index to the specific resource descriptor that this
	device consumes from in the current resource template for the device
	object pointed to in Resource Source
String (Resource Source):
	(Optional) If present, the device that uses this descriptor consumes
	its resources from the resources produced by the named device object.
	If not present, the device consumes its resources out of a global pool.
	If not present, the device consumes this resource from its hierarchical
	parent.
*/

Name (p429, Package() {

	// Byte 4 (General Flags) of Word Address Space Descriptor

	Buffer () {0x88, 0x0d, 0x00, 0x02, 0x00, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe, 0x79, 0x00},
	Buffer () {0x88, 0x0d, 0x00, 0x02, 0x02, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe, 0x79, 0x00},
	Buffer () {0x88, 0x0d, 0x00, 0x02, 0x08, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe, 0x79, 0x00},
	Buffer () {0x88, 0x0d, 0x00, 0x02, 0x0a, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe, 0x79, 0x00},
	Buffer () {0x88, 0x0d, 0x00, 0x02, 0x04, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe, 0x79, 0x00},
	Buffer () {0x88, 0x0d, 0x00, 0x02, 0x06, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe, 0x79, 0x00},
	Buffer () {0x88, 0x0d, 0x00, 0x02, 0x0c, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe, 0x79, 0x00},
	Buffer () {0x88, 0x0d, 0x00, 0x02, 0x0e, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe, 0x79, 0x00},
	Buffer () {0x88, 0x0d, 0x00, 0x02, 0x01, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe, 0x79, 0x00},
	Buffer () {0x88, 0x0d, 0x00, 0x02, 0x03, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe, 0x79, 0x00},
	Buffer () {0x88, 0x0d, 0x00, 0x02, 0x09, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe, 0x79, 0x00},
	Buffer () {0x88, 0x0d, 0x00, 0x02, 0x0b, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe, 0x79, 0x00},
	Buffer () {0x88, 0x0d, 0x00, 0x02, 0x05, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe, 0x79, 0x00},
	Buffer () {0x88, 0x0d, 0x00, 0x02, 0x07, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe, 0x79, 0x00},
	Buffer () {0x88, 0x0d, 0x00, 0x02, 0x0d, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe, 0x79, 0x00},
	Buffer () {0x88, 0x0d, 0x00, 0x02, 0x0f, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe, 0x79, 0x00},

	// Particular cases

	Buffer () {0x88, 0x0d, 0x00, 0x02, 0x01, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe, 0x79, 0x00},
	Buffer () {0x88, 0x0d, 0x00, 0x02, 0x01, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe, 0x79, 0x00},

	// Resource Source

	Buffer () {0x88, 0x0f, 0x00, 0x02, 0x01, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe,
		0x01, 0x00, 0x79, 0x00},
	Buffer () {0x88, 0x10, 0x00, 0x02, 0x01, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe,
		0x0f, 0x50, 0x00, 0x79, 0x00},
	Buffer () {0x88, 0x13, 0x00, 0x02, 0x01, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe,
		0xf0, 0x50, 0x41, 0x54, 0x48, 0x00, 0x79, 0x00},
	Buffer () {0x88, 0xd7, 0x00, 0x02, 0x01, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe,
		0xff,
		0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,
		0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30,
		0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38,
		0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40,
		0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48,
		0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50,
		0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58,
		0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f, 0x60,
		0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68,
		0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70,
		0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78,
		0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x20, 0x21,
		0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29,
		0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31,
		0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39,
		0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41,
		0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49,
		0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51,
		0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59,
		0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f, 0x60, 0x61,
		0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69,
		0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71,
		0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79,
		0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x20, 0x21, 0x22,
		0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a,
		0x00, 0x79, 0x00},

	// Particular cases

	Buffer () {0x88, 0x1b, 0x00, 0x02, 0x0f, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe,
		0xff, 0x50, 0x41, 0x54, 0x48, 0x50, 0x41, 0x54,
		0x48, 0x50, 0x41, 0x54, 0x48, 0x00, 0x79, 0x00},
	Buffer () {0x88, 0x1b, 0x00, 0x02, 0x0f, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xff, 0x50, 0x41, 0x54, 0x48, 0x50, 0x41, 0x54,
		0x48, 0x50, 0x41, 0x54, 0x48, 0x00, 0x79, 0x00},

	// 20051021, relaxation for omitted ResourceSource (bug-fix 70 rejection)
	Buffer () {0x88, 0x0e, 0x00, 0x02, 0x01, 0x00,
		0xf7, 0xf6, 0xf9, 0xf8, 0xfb, 0xfa, 0xfd, 0xfc, 0xff, 0xfe,
		0x0f, 0x79, 0x00},
})

Method(RT12)
{
	Name(ts, "RT12")

	// Emit test header, set the filename

	THDR (ts, "WordBusNumber Resource Descriptor Macro", __FILE__)

    // Main test case for packages above

	m330(ts, 25, "p428", p428, p429)

    // Check resource descriptor tag offsets

	Store (
		ResourceTemplate () {
			WordBusNumber (ResourceProducer, MinNotFixed, MaxNotFixed, PosDecode,
				0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff, , , WBN0)
			WordBusNumber (ResourceConsumer, MinNotFixed, MaxNotFixed, PosDecode,
				0xf6f7, 0xf8f9, 0xfafb, 0xfcfd, 0xfeff, , , WBN1)
		}, Local0)

	m331(ts, 1,  WBN0._DEC, 0x21, WBN1._DEC, 0xa1, "_DEC")
	m331(ts, 2,  WBN0._MIF, 0x22, WBN1._MIF, 0xa2, "_MIF")
	m331(ts, 3,  WBN0._MAF, 0x23, WBN1._MAF, 0xa3, "_MAF")
	m331(ts, 7,  WBN0._GRA, 0x30, WBN1._GRA, 0xB0, "_GRA")
	m331(ts, 8,  WBN0._MIN, 0x40, WBN1._MIN, 0xC0, "_MIN")
	m331(ts, 9,  WBN0._MAX, 0x50, WBN1._MAX, 0xD0, "_MAX")
	m331(ts, 10, WBN0._TRA, 0x60, WBN1._TRA, 0xE0, "_TRA")
	m331(ts, 11, WBN0._LEN, 0x70, WBN1._LEN, 0xF0, "_LEN")
}
