#ifndef		IDE_H_
# define	IDE_H_

# define CONFIG_ADDRESS	0xCF8
# define CONFIG_DATA	0xCFC

# define CONFIG_ADDRESS_FORMAT(BUS, DEVICE, FUNCTION, OFFSET)		\
  ((1 << 31) | (BUS << 16) | (DEVICE << 11) | (FUNCTION << 8) | OFFSET)

void	ide_init();

#endif
