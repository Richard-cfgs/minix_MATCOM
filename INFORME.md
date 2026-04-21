Integrantes:
Richard Alejandro Reyes Gracia C212
Jorge Julio de Leon Massorca C212

2. Desarrollo y resultados por componentes
2.1. Instalacion y configuracion de minix
El emulador que use fue Qemu 10.2.2 usado porque mi computadora es ARM y 
Minix 3.4.0 requiere x86, VirtuaBox no se usóxq este solo virtualiza

2GB de RAM Suficiente para compilar sin lentitud, sin desperdiciar recursos del 
host
1 núcleo de CPU MINIX no requiere más; emular múltiples núcleos en QEMU/ARM 
añade sobrecarga
20GB de disco duro Eepacio suficiente para código fuente y compilaciones; 
formato dinámico ahorra espacio en el host
IPv4 only con DHCP y redirección de pueros (SSH en puerto 7722) modo usuario 
simple, evita problemas de IPv6 en MINIX 3

El 1er emulador que use fue UTM pero no reconoocía la ISO por problemas de 
compatibiliad por lo cual cambiié a Qemu
QEMU dió error "file driver requires regular file" por punto en la ruta 
(richarda.) por lo cual moví los archivos a ~/minix_vm y usar rutas relativas
Error de SSL al hacer git push se arregló desabilitandoverificación SSL con 
git config --global http.sslVerify false 

Herramientas adicionales instaladas
Git: Clonar repositorio oficial (/usr/src) y subir cambios a GitHub
Nano: Editar archivos como /usr/src/etc/motd
