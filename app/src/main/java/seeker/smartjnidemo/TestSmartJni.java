package seeker.smartjnidemo;

import java.util.Locale;

/**
 * @author Seeker
 * @date 2019/1/17/017  15:13
 */
public class TestSmartJni {

    private int code;

    private boolean result;

    private byte aByte;

    @Override
    public String toString() {
        return String.format(Locale.CHINA,"code[%d],result[%b],aByte[%02x]",code,result, aByte & 0xff);
    }
}
