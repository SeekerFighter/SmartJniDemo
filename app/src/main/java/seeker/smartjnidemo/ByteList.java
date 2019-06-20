package seeker.smartjnidemo;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Seeker
 * @date 2019/6/20/020  13:48
 * @describe TODO
 */
public class ByteList {

    private List<Byte> bytes;

    public ByteList(){
        bytes = new ArrayList<>();
    }

    public void add(Byte aByte) {
        bytes.add(aByte);
    }

    @Override
    public String toString() {
        return listToString();
    }

    private String listToString(){
        StringBuilder sb = new StringBuilder();
        for (Byte b:bytes){
            sb.append(String.format("0x%02X ", b));
        }
        return sb.toString();
    }


}
