#ifndef		IDE_H_
# define	IDE_H_

# define PCI_INDEX_PORT	0xCF8
# define PCI_DATA_PORT	0xCFC

# define PCI_INDEX_FORMAT(BUS, DEVICE, FUNCTION, REGISTER)		\
  ((1 << 31) | (BUS << 16) | (DEVICE << 11) | (FUNCTION << 8) | ((REGISTER >> 2) << 2))

# define PCI_MAX_BUSES		256	// 2^(24 - 16), [30:24] are reserved
# define PCI_MAX_DEVICES	32	// 2^(16 - 11)
# define PCI_MAX_FUNCTIONS	8	// 2^(11 - 8)
# define PCI_MAX_REGISTERS	64	// 2^(8 - 2), [1:0] must be to 0

void	ide_init();

#endif
