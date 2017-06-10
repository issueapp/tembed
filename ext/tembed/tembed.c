#include <ruby.h>
#include <stdio.h>
#include <stdlib.h>

VALUE mTembed;

void Init_tembed();
static VALUE method_call_bang(VALUE module, VALUE thing);

static VALUE embed(const char *path);
static void fatal();

void Init_tembed()
{
  mTembed = rb_define_module("Tembed");
  rb_define_module_function(mTembed, "call!", method_call_bang, 1);
}

static VALUE method_call_bang(VALUE module, VALUE thing)
{
  if (rb_respond_to(thing, rb_intern("path")))
  {
    thing = rb_funcall(thing, rb_intern("path"), 0);
  }

  thing = rb_funcall(thing, rb_intern("to_s"), 0);

  return embed(StringValueCStr(thing));
}

static VALUE embed(const char *path)
{
     FILE *inways = fopen(path, "rb+");

     if (inways)
     {
        int a,x;
        char type[5];

        type[4]=0;

        fseek(inways,12,0);

        for (;;) {
           for (x=0;x<4;x++) if (EOF == (type[x] = getc(inways))) fatal();

           if (!strcmp(type,"OS/2"))
           {
              int length;
              unsigned long loc, fstype, sum=0;
              loc=ftell(inways); /* location for checksum */
              for (x=4;x--;) if (EOF == getc(inways)) fatal();
              fstype  = fgetc(inways) << 24;
              fstype |= fgetc(inways) << 16;
              fstype |= fgetc(inways) << 8 ;
              fstype |= fgetc(inways)      ;
              length  = fgetc(inways) << 24;
              length |= fgetc(inways) << 16;
              length |= fgetc(inways) << 8 ;
              length |= fgetc(inways)      ;
/*              printf("fstype: %d length: %d\n",fstype,length);*/
              if (fseek(inways,fstype+8,0)) fatal();
              fputc(0,inways);
              fputc(0,inways);
              fseek(inways,fstype,0);
              for (x=length;x--;)
                  sum += fgetc(inways);
              fseek(inways,loc,0); /* write checksum */
              fputc(sum>>24,inways);
              fputc(255&(sum>>16),inways);
              fputc(255&(sum>>8), inways);
              fputc(255&sum    ,  inways);
              fclose(inways);

              return Qtrue;
           }
           for (x=12;x--;) if (EOF == getc(inways)) fatal();
        }

        return Qtrue;
     }
     else {
        printf("Fail to open file: %s\n", path);
        return Qfalse;
     }
}

static void fatal() {
  fprintf(stderr,"Malformed TTF file.\n");
  exit(-1);
}
