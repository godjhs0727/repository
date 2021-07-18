using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour
{
    public int maxHealth;
    public int curHealth;

    Rigidbody rigid;
    BoxCollider boxCollider;
    Material mat;

    void Awake()
    {
        rigid = GetComponent<Rigidbody>();
        boxCollider = GetComponent<BoxCollider>();
        mat = GetComponent<MeshRenderer>().material;
        //Material은 MeshRenderer에서 접근가능
    }
    void OnTriggerEnter(Collider other)
    {
            if (other.tag == "Melee")
            {
                Weapon weapon = other.GetComponent<Weapon>();
                curHealth -= weapon.damage;
                Vector3 reactVac = transform.position - other.transform.position;
                StartCoroutine(OnDamage(reactVac, false));

                Debug.Log("Melee : " + curHealth);
            }
            else if (other.tag == "Bullet")
            {
                Bullet bullet = other.GetComponent<Bullet>();
                curHealth -= bullet.damage;
                Vector3 reactVac = transform.position - other.transform.position;
                Destroy(other.gameObject);

                StartCoroutine(OnDamage(reactVac, false));

                Debug.Log("Bullet : " + curHealth);
            }
    }
    public void HitByGrenade(Vector3 explosionPos)
    {
        curHealth -= 100;
        Vector3 reactVac = transform.position - explosionPos;
        StartCoroutine(OnDamage(reactVac, true));
    }

    IEnumerator OnDamage(Vector3 reactVac, bool isGrenade)
    {
        mat.color = Color.red;
        yield return new WaitForSeconds(0.1f);

        if(curHealth > 0)
        {
            mat.color = Color.white;
        }
        else
        {
            mat.color = Color.gray;
            gameObject.layer = 14;

            if (isGrenade)
            {
                reactVac = reactVac.normalized;
                reactVac += Vector3.up * 3;

                rigid.freezeRotation = false;
                rigid.AddForce(reactVac * 5, ForceMode.Impulse);
                rigid.AddTorque(reactVac * 15, ForceMode.Impulse);
            }
            else
            {
                reactVac = reactVac.normalized;
                reactVac += Vector3.up;
                rigid.AddForce(reactVac * 5, ForceMode.Impulse);
            }

            Destroy(gameObject, 4);
        }
    }
}
