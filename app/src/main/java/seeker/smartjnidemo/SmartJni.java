package seeker.smartjnidemo;

import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

/**
 * @author Seeker
 * @date 2019/1/17/017  15:13
 */
public class SmartJni {

    private int code;

    private boolean result;

    private byte aByte;

    private int Jint;

    private int Jint2;

    private byte jbyte;

    private float Jfloat;

    private long Jlong;

    private Integer jobject ;

    private short Jshort;

    private double Jdouble;

    private ByteList obj;

    private List<Byte> byteList;

    @Override
    public String toString() {
        return String.format(Locale.CHINA,"code[%d]\nresult[%b]\naByte[0x%02X]\njint[%d]\nJint2[%d]\n" +
                        "jbyte[0x%02X]\njobject[%d]\nJfloat[%f]\nJlong[%d]\nJshort[%d]\nJdouble[%f]\n%s\n%s",
                code,result, aByte & 0xff,Jint,Jint2,jbyte&0xff, jobject,Jfloat,Jlong,Jshort,Jdouble,obj,listToString(byteList));
    }

    public void setJint(int jint) {
        this.Jint = jint;
    }

    public void setJint2(int jint2) {
        Jint2 = jint2;
    }

    public void setJbyte(byte jbyte) {
        this.jbyte = jbyte;
    }

    public void setJobject(Integer jobject) {
        this.jobject = jobject;
    }

    public void setJfloat(float jfloat) {
        this.Jfloat = jfloat;
    }

    public void setJlong(long jlong) {
        this.Jlong = jlong;
    }

    public void setMuiti(double jdouble,short jshort){
        this.Jdouble = jdouble;
        this.Jshort = jshort;
    }

    public void setObj(ByteList obj) {
        this.obj = obj;
    }

    public void setByteList(List<Byte> byteList) {
        this.byteList = byteList;
    }

    private String listToString(List<Byte> byteList){
        if (byteList == null) return "NULL_byteList";
        StringBuilder sb = new StringBuilder();
        for (Byte b:byteList){
            sb.append(String.format("0x%02X ", b));
        }
        return sb.toString();
    }

}
