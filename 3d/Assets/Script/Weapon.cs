using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Weapon : MonoBehaviour
{
    public enum Type { Melee, Range};
    public Type type;
    public int damage;
    public float rate;
    public BoxCollider meleeArea;
    public TrailRenderer trailEffect;

    public void Use()
    {
        if(type == Type.Melee)
        {
            StopCoroutine("Swing");
            StartCoroutine("Swing");
        }
    }
    IEnumerator Swing() //�ڷ�ƾ Invoke���
    {
        //1
        yield return new WaitForSeconds(0.1f);
        meleeArea.enabled = true;
        trailEffect.enabled = true;

        yield return new WaitForSeconds(0.3f);
        meleeArea.enabled = false;

        yield return new WaitForSeconds(0.5f);
        trailEffect.enabled = false;
    }

    //Use() ���η�ƾ -> Swing() �����ƾ -> Use() ���η�ƾ
    //Use() ���η�ƾ + Swing() �ڷ�ƾ(Co-Op)
}